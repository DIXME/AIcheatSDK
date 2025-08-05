#include <kmbox/kmboxNet.h>
#include <types.hpp>
#include <string>

class Kmbox {
   // you can make your own aswell!
public:
   bool connected;
   void move(int x, int y, int ms){
      if(this->connected){
         kmNet_mouse_move_auto(x,y,ms);
      };
   };

   void move(short x, short y){
      if(this->connected){
         kmNet_mouse_move(x,y);
      };
   };

   bool connect(char* ip, char* port, char* mac){
      bool result = kmNet_init(ip,port,mac)==0;
      this->connected = result;
      return result;
   };

   void test(){
      if(this->connected){
         this->move(500,500);
      };
   };
};