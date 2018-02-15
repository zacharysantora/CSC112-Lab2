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
    
    //Return the ending x and y
    virtual int ex();
    virtual int ey();

private:
    int _ex, _ey;
    int pointCount;
};

#endif