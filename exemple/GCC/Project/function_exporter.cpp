#include "function_exporter.h"

extern "C" void deleteObject(Object *object)
{
    delete object;
}

__declspec(dllexport) void start(Object *object)
{
    object->start();
}

extern "C" __declspec(dllexport) void update(Object* object){
    object->update();
}

extern "C" __declspec(dllexport) void render(Object* object){
    object->render();
}

