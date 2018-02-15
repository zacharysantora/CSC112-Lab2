/*
 * Draw a sierpinski triangle by indicating apex and height.
 * Author: Robert Lowe
 */
#ifndef SIERPINSKI_H
#define SIERPINSKI_H
#include <vector>
#include "shape.h"

class Sierpinski : public Shape
{
public:
    //constructor
    Sierpinski();

    //required widget functions
    virtual void display();
    virtual void handleEvent(Event *e);

    //required shape function
    virtual bool isComplete();
    virtual void addPoint(int _x, int _y);
  
private:
    std::vector<std::vector<bool>> rows;
    int dy;
    int pointCount;
    int rowCount;
};

#endif
