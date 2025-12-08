#ifndef __SCRIPT_H__
#define __SCRIPT_H__

#include <project.h>

#include <string>
#include <filesystem>
#include <vector>

class Script{
    public:
        Script(const std::string& _name, Project* _project);

        Script& create();
        Script& addInclude(const std::string& includePath);
        Script& registerClass(const std::string& className);
        Script& addFunction(const std::string& functionName);
        Script& addMethodeToClass(const std::string& className, const std::string& methodeName);

        bool classExist(const std::string& className);
        bool functionExist(const std::string& functionName);
        bool methodeExist(const std::string& className, const std::string& methodeName);

        int findClassIndex(const std::string& className);

        void build();
    private:
        Project* project;

        std::string name;
        std::filesystem::path hPath;
        std::filesystem::path cppPath;

        std::vector<std::string> includes;
        std::vector<std::string> classes;
        std::vector<std::vector<std::string>> methodes;
        std::vector<std::string> functions;
};

#endif