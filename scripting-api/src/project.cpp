#include <project.h>
#include <iostream>

Project::Project(const std::string& projectEmplacement, const std::string& projectName){
    emplacement = projectEmplacement;
    name = projectName;
}

Project& Project::create()
{
    if(std::filesystem::create_directories((emplacement.string()+"/"+name).c_str())){
        if(!std::filesystem::create_directories((emplacement.string()+"/"+name+"/cmake").c_str())){
            std::cerr << "[ERROR] : " << (emplacement.string()+"/"+name+"/cmake").c_str() << " can't be created..." << std::endl;
        }
        if(!std::filesystem::create_directories((emplacement.string()+"/"+name+"/scripts").c_str())){
            std::cerr << "[ERROR] : " << (emplacement.string()+"/"+name+"/scripts").c_str() << " can't be created..." << std::endl;
        }
        if(!std::filesystem::create_directories((emplacement.string()+"/"+name+"/build").c_str())){
            std::cerr << "[ERROR] : " << (emplacement.string()+"/"+name+"/build").c_str() << " folder can't be created..." << std::endl;
        }
    }else{
        std::cerr << "[ERROR] : " << (emplacement.string()+"/"+name).c_str() << " folder can't be created..." << std::endl;
    }
    return *this;
}

void Project::build()
{
    std::system(("cmake -G \"Visual Studio 17 2022\" -S ./"+name+" -B build -DCMAKE_TOOLCHAIN_FILE=\"C:\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake\"").c_str());
    std::system("cmake --build build");
}

std::string Project::getName()
{
    return name;
}
