#include <script.h>
#include <project.h>
#include <object.h>

#include <windows.h>

#include <iostream>

typedef Object*(*createPlayer)();
typedef void(*deleteObject)(Object*);
typedef void(*start)(Object*);
typedef void(*update)(Object*);
typedef void(*render)(Object*);

int main(){
    Project project("./", "Project");
    project.create();

    // Ne pas toucher a part si on veut reset les script
    // Script playerScript("Player", &project);
    // playerScript.registerClass("Player")
    //             .addInclude("object.h")
    //             .addMethodeToClass("Player","start()")
    //             .addMethodeToClass("Player","update()")
    //             .addMethodeToClass("Player","render()")
    //             .build();

    // playerScript.prepareToExport();

    project.build(); // Compiler les scripts en dll

    HMODULE plugins = LoadLibraryA("./Project/build/libS_API.dll");
    if(!plugins) std::cout << "Plugin not found" << std::endl;

    createPlayer createPlayerFunc = (createPlayer)GetProcAddress(plugins, "createPlayer");
    if(!createPlayerFunc) std::cout << "createPlayerFunc not found" << std::endl;

    deleteObject deleteObjectFunc = (deleteObject)GetProcAddress(plugins, "deleteObject");
    if(!deleteObjectFunc) std::cout << "deleteObjectFunc not found" << std::endl;

    start startFunc = (start)GetProcAddress(plugins, "start");
    if(!startFunc) std::cout << "startFunc not found" << std::endl;

    update updateFunc = (update)GetProcAddress(plugins, "update");
    if(!updateFunc) std::cout << "udpateFunc not found" << std::endl;

    render renderFunc = (render)GetProcAddress(plugins, "render");
    if(!renderFunc) std::cout << "renderFunc not found" << std::endl;

    Object* player = nullptr;
    if(createPlayerFunc)
        player = createPlayerFunc();

    startFunc(player);
    renderFunc(player);
    updateFunc(player);
          
    deleteObjectFunc(player);
    FreeLibrary(plugins);

    return 0;
}