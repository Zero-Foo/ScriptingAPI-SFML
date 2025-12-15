#include "pluginObjectFunctions.h"
#include <iostream>

PluginObjectManager::PluginObjectManager(const std::string &pluginPath)
{
    if(plugin = LoadLibraryA(pluginPath.c_str()); !plugin) std::cerr << "Plugin not found" << std::endl;
    if(deleteObj = (deleteObject)GetProcAddress(plugin, "deleteObject"); !deleteObj) std::cerr << "deleteObject not found" << std::endl;
    if(startObj = (startObject)GetProcAddress(plugin, "start"); !startObj) std::cerr << "startObject not found" << std::endl;
    if(updateObj = (updateObject)GetProcAddress(plugin, "update"); !updateObj) std::cerr << "updateObject not found" << std::endl;
    if(renderObj = (renderObject)GetProcAddress(plugin, "render"); !renderObj) std::cerr << "renderObject not found" << std::endl;
}

PluginObjectManager::~PluginObjectManager()
{
    FreeLibrary(plugin);
}

void PluginObjectManager::addObjectCreator(const std::string &funcName)
{
    creationFuncs.addFunc(funcName, (functionObject)GetProcAddress(plugin, funcName.c_str()));
}

functionObject PluginObjectManager::getObjectCreator(const std::string &funcName)
{
    return creationFuncs.getFunc(funcName);
}

void PluginObjectManager::del(Object *obj)
{
    if(deleteObj)
        deleteObj(obj);
}

void PluginObjectManager::start(Object *obj)
{
    if(startObj)
        startObj(obj);
}

void PluginObjectManager::update(Object *obj, float dt)
{
    if(updateObj)
        updateObj(obj, dt);
}

void PluginObjectManager::render(Object *obj, sf::RenderTarget& target)
{
    if(renderObj)
        renderObj(obj, target);
}
