//Hexagon class. Draw a hexagon given the center and a corner
#ifndef HEXAGON_H
#define HEXAGON_H
#include "shape.h"

class Hexagon : public Shape
{
public:
    Hexagon(); //constructor
    
    //Widget functions
    virtual void display();
    virtual void handleEvent(Event *e);
    
    //Hexagon functions
    virtual bool isComplete();
    virtual void addPoint(int _x, int _y);
    
private:
    //x of center, each corner, and delta x
    int x1, x2, x3, x4, x5, x6, dx;
    
    //y of center, each corner, and delta y
    int y1, y2, y3, y4, y5, y6, dy;
    
    //Radius of hexagon
    int r;
    
    int pointCount;
};

#endif