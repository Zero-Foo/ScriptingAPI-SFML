#ifndef __PLUGIN_OBJECT_FUNCTIONS__
#define __PLUGIN_OBJECT_FUNCTIONS__

#include <object.h>

#include <windows.h>

#include <unordered_map>
#include <string>

#define CREATEPOINTERFUNC(FUNC_NAME, RETURN_TYPE, ...) typedef RETURN_TYPE (*FUNC_NAME)(__VA_ARGS__)
#define CREATEOBJECTPOINTERFUNC(OBJNAME, ...) CREATEPOINTERFUNC(create##OBJNAME, Object*, __VA_ARGS__)

CREATEPOINTERFUNC(functionObject, Object*);
CREATEPOINTERFUNC(deleteObject, void, Object*);
CREATEPOINTERFUNC(startObject, void, Object*);
CREATEPOINTERFUNC(updateObject, void, Object*);
CREATEPOINTERFUNC(renderObject, void, Object*);

class ObjectCreationFunc{
    std::unordered_map<std::string, functionObject> createFuncs;
    public:
        void addFunc(std::string name, functionObject func){
            createFuncs.insert({name, func});
        }
        functionObject getFunc(std::string name){
            if(auto func = createFuncs.find(name)->second){
                return func;
            }
            return nullptr;
        }
};

class PluginObjectManager{
    public:
        PluginObjectManager(const std::string& pluginPath);
        ~PluginObjectManager();

        void addObjectCreator(const std::string& funcName);
        functionObject getObjectCreator(const std::string& funcName);

        void del(Object* obj);
        void start(Object* obj);
        void update(Object* obj);
        void render(Object* obj);

    private:
        HMODULE plugin;
        ObjectCreationFunc creationFuncs;
        deleteObject deleteObj = nullptr;
        startObject startObj = nullptr;
        updateObject updateObj = nullptr;
        renderObject renderObj = nullptr;
};

#endif