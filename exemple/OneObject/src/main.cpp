#include <script.h>
#include <project.h>

int main(){
    Project project("./", "Project");
    project.create();

    Script script("Player", &project);
    script.create()
          .registerClass("Player")
          .addFunction("Start()")
          .addMethodeToClass("Player", "start()")
          .addMethodeToClass("Player", "update()")
          .addMethodeToClass("Player", "draw()")
          .build();


          
    return 0;
}