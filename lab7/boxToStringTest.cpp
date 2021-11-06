#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"


int main() {

  struct Box b1, b2;

  initBox(&b1, 3, 4, 3.256, 4.256);  
  assertEquals("ul=(3,4),w=3.3,h=4.3", boxToString(b1,2), "boxToString(b1)");
  assertEquals("ul=(3,4),w=3.26,h=4.26", boxToString(b1,3), "boxToString(b1)");
  assertEquals("ul=(3,4),w=3.256,h=4.256", boxToString(b1,4), "boxToString(b1)");

  initBox(&b2, 3.1415926, 4.3415, 6.898494, 10.1001);
  assertEquals("ul=(3.1,4.3),w=6.9,h=10", boxToString(b2,2), "boxToString(b2)");
  assertEquals("ul=(3.14,4.34),w=6.9,h=10.1", boxToString(b2,3), "boxToString(b2)");
  assertEquals("ul=(3.14159,4.3415),w=6.89849,h=10.1001", boxToString(b2,6), "boxToString(b2)");

  return 0;
}
