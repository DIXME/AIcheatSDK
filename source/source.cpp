#include "source.hpp"

int main(){
   init();
   while(!glfwWindowShouldClose(window))
      loop();
   terminate();
   return 0; 
}