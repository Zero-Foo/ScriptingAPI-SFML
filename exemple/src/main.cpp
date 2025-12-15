#include <script.h>
#include <project.h>
#include <object.h>

#include <pluginObjectFunctions.h>

#include <SFML/Graphics/RenderWindow.hpp>

#include <windows.h>

#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Exemple");

    Project project("./", "Project");
    project.create();

    // // Ne pas toucher a part si on veut reset les script
    // Script playerScript("Player", &project);
    // playerScript.create()
    //             .registerClass("Player")
    //             .addInclude("object.h")
    //             .addMethodeToClass("Player","start()")
    //             .addMethodeToClass("Player","update(float dt)")
    //             .addMethodeToClass("Player","draw(sf::RenderTarget& target)")
    //             .build();

    // playerScript.prepareToExport();

    // Script invScript("Inventory", &project);
    // invScript.create()
    //             .registerClass("Inventory")
    //             .addInclude("object.h")
    //             .addMethodeToClass("Inventory","start()")
    //             .addMethodeToClass("Inventory","update(float dt)")
    //             .addMethodeToClass("Inventory","draw(sf::RenderTarget& target)")
    //             .build();

    // invScript.prepareToExport();

    project.build(); // Compiler les scripts en dll

    PluginObjectManager pluginManager("./Project/build/Debug/S_API.dll");
    pluginManager.addObjectCreator("createPlayer");
    pluginManager.addObjectCreator("createInventory");

    Object* player = nullptr;
    Object* inventory = nullptr;
    if(auto creator = pluginManager.getObjectCreator("createPlayer"))
        player = creator();

    if(auto creator = pluginManager.getObjectCreator("createInventory"))
        inventory = creator();

    pluginManager.start(player);
    pluginManager.start(inventory);
    
    while(window.isOpen()){
        while(const auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        pluginManager.update(player, 0);
        pluginManager.update(inventory, 0);

        window.clear();

        pluginManager.render(player, window);
        pluginManager.render(inventory, window);

        window.display();
    }


    pluginManager.del(player);
    pluginManager.del(inventory);
    

    return 0;
}