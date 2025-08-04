#include <kmbox/kmboxNet.h>
namespace Kmbox {
   bool connect(char* ip, char* port, char* mac){
      return kmNet_init(ip,port,mac);
   }

   bool test(){
      return kmNet_mouse_move(500,500);
   }
}

namespace Macku {
   bool connect(){
      return false;
   }

   bool test(){
      return false;
   }
}

namespace Native {
   bool connect(){
      return false;
   }

   bool test(){
      return false;
   }
}