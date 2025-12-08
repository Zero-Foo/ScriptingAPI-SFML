#ifndef __PROJECT_H__
#define __PROJECT_H__

#include <string>
#include <filesystem>

class Project{
    public:
        Project(const std::string& projectEmplacement, const std::string& projectName);
        Project& create();

        void build();

        std::string getName();

    private:
        std::string name;
        std::filesystem::path emplacement;
};

#endif