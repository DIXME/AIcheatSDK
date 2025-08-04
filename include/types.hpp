#include <vector>
#include <functional>
#include <memory>
#include <string>

typedef struct {
   virtual void move(int x, int y, int ms = 0){};
   virtual void keyDown(int key){};
   virtual void keyUp(int key){};
   virtual void key(int key){};
} MouseAPI_t;

enum Mode {
   native,
   kmbox,
   macku
};

typedef std::unique_ptr<MouseAPI_t>& MouseAPI;

// make native, kmbox, and macku api's

typedef struct {
   int x;
   int y;
} Point;

typedef std::vector<Point> Points; 

// recreate a recoil pattern (Image => Points)
void copyPattern(Points points, MouseAPI api){}

typedef struct {
   int x_mv;
   int y_mv;
   int delay;
} NormalScript;

typedef struct {
   Points points;
} AdvancedScript;

typedef struct {
   std::string script; // turn into a function or just execute
   int key; // key to activate it
} Macro;