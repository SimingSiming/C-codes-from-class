#ifndef BOXFUNCS_H
#define BOXFUNCS_H

#include <string>
using std::string;
#include "shapes.h"


string pointToString(Point p, int precision=3);
string boxToString(Box b, int precision=3);
double distanceBetween(Point p, Point q);
bool pointsApproxEqual(Point p1, Point p2, double tolerance=0.0001);
bool boxesApproxEqual(Box b1, Box b2, double tolerance=0.0001);


//precondition: given a struct pointer and two double variables xVal and yVal. 
//postcondition: point has been initialized by xVal and yVal.
void initPoint(struct Point *p, double xVal, double yVal);

void initBox(struct Box *b, double ulx, double uly, double w, double h);

double areaOfBox(Box b);


#endif // BOXFUNCS_H
