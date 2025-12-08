#include <script.h>

#include <string>
#include <fstream>
#include <iostream>

Script::Script(const std::string &_name, Project* _project)
{
    name = _name;
    project = _project;
}

Script &Script::create()
{
    hPath = ("./"+project->getName()+"/scripts/"+name+".h");
    if(std::filesystem::exists(hPath)){
        std::ofstream hFile(hPath);
        hFile.clear();
        hFile.close();
    }
    std::ofstream hFile(hPath);
    hFile << "#pragma once" << std::endl;
    hFile.close();

    cppPath = ("./"+project->getName()+"/scripts/"+name+".cpp");
    if(std::filesystem::exists(cppPath)){
        std::ofstream cppFile(cppPath);
        cppFile.clear();
        cppFile.close();
    }
    std::ofstream cppFile(cppPath);
    cppFile << "#include \"" << name << ".h\"" << std::endl;
    cppFile.close();
    return *this;
}

Script &Script::addInclude(const std::string &includePath)
{
    includes.push_back(includePath);
    return *this;
}

Script &Script::registerClass(const std::string &className)
{
    if(!classExist(className)){
        classes.push_back(className);
        methodes.push_back({});
    }
    return *this;
}

Script &Script::addFunction(const std::string &functionName)
{
    if(!functionExist(functionName))
        functions.push_back(functionName);
    return *this;
}

Script &Script::addMethodeToClass(const std::string &className, const std::string &methodeName)
{
    if(!methodeExist(className, methodeName)){
        if(int index = findClassIndex(className); index != -1)
            methodes[index].push_back(methodeName);
    }
    return *this;
}

bool Script::classExist(const std::string &className)
{
    for(auto c : classes)
        if(c == className)
            return true;
    return false;
}

bool Script::functionExist(const std::string &functionName)
{
    for(auto c : functions)
        if(c == functionName)
            return true;
    return false;
}

bool Script::methodeExist(const std::string &className, const std::string &methodeName)
{
    for(int i = 0; i < classes.size(); i++){
        if(classes[i] == className){
            for(auto methode : methodes[i])
                if(methode == methodeName)
                    return true;
        }
    }
    return false;
}

int Script::findClassIndex(const std::string &className)
{
    for(int i = 0; i < classes.size(); i++)
        if(classes[i] == className)
            return i;
    return -1;
}

void Script::build()
{
    // H File
    if(std::filesystem::exists(hPath)){
        std::ofstream hFile(hPath, std::ios_base::app);
        hFile << std::endl;
        //Include
        for(auto include : includes)
            hFile << "#include <" << include << ">" << std::endl;
        hFile << std::endl;
        for(int i = 0; i < classes.size(); i++){
            // Classes
            hFile << "class " << classes[i] << " : public Object {" << std::endl;
            hFile << "public:" << std::endl;

            //Methode
            for(auto methode : methodes[i]){
                hFile << "\tvoid " << methode;
                if(methode == "update()" || methode == "start()" || methode == "render()")
                    hFile << " override";
                hFile << ";" << std::endl;
            }

            hFile << "};\n" << std::endl;;
        }
        // Functions
        for(auto func : functions){
            hFile << "void " << func << ";" << std::endl;
        }
    }
    
    // Cpp File
    if(std::filesystem::exists(cppPath)){
        std::ofstream cppFile(cppPath, std::ios_base::app);
        cppFile << std::endl;
        for(int i = 0; i < classes.size(); i++){
            // Classes

            //Methode
            for(auto methode : methodes[i]){
                cppFile << "void " << classes[i] << "::" << methode << "{\n" << std::endl;
                cppFile << "}\n" << std::endl;
            }

        }
        // Functions
        for(auto func : functions){
            cppFile << "void " << func << "{\n" << std::endl;
            cppFile << "}\n" << std::endl;
        }
    }
}

void Script::prepareToExport()
{
    if(std::filesystem::exists(("./"+project->getName()+"/function_exporter.h"))){
        std::ofstream exportFile(("./"+project->getName()+"/function_exporter.h").c_str(), std::ios_base::app);
        exportFile << std::endl;
        for(auto c : classes)
            exportFile << "CREATEOBJECT(" << c << ")";
        exportFile.close();
    }else{
        std::cerr << "[ERROR] : " << ("./"+project->getName()+"/function_exporter.h") << " not found" << std::endl;
    }
}
