#include <vector>
#include <functional>
#include <memory>
#include <string>

enum Mode {
   native,
   kmbox,
   macku
};

// make native, kmbox, and macku api's

typedef struct {
   int x;
   int y;
} Point;

typedef std::vector<Point> Points; 

// recreate a recoil pattern (Image => Points)
void copyPattern(Points points){}

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