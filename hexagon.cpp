#include <iostream>
#include <cmath>
#include "shape.h"
#include "term.h"
#include "hexagon.h"

using namespace std;

Hexagon::Hexagon()
{
    _ex = -1;
    _ey = -1;
    pointCount = 0;
}


//Display hexagon
void Hexagon::display()
{
    //Check if hexagon is complete
    if(! isComplete())
    {
        return;
    }
    
    //Calculate the deltas and radius
    dx = abs(x1 - xc);
    dy = abs(y1 - yc);
    r = sqrt(dx * dx + dy * dy)
    
    //Calculate each corner
    x2 = xc - dx;
    y2 = yc + dy;
    
    x3 = xc - r;
    y3 = yc;
    
    x4 = xc - dx;
    y4 = yc - dy;
    
    x5 = xc + dx;
    y5 = yc - dy;
    
    x6 = xc + r;
    y6 = yc;
    
    //Display the hexagon
    Line l1,l2,l3,l4,l5,l6;
    
    l1.addPoint(x1,y1);
    l1.addPoint(x2,y2);
    l1.display();
    
    l1.addPoint(x2,y2);
    l1.addPoint(x3,y3);
    l1.display();
    
    l1.addPoint(x3,y3);
    l1.addPoint(x4,y4);
    l1.display();
    
    l1.addPoint(x4,y4);
    l1.addPoint(x5,y5);
    l1.display();
    
    l1.addPoint(x5,y5);
    l1.addPoint(x6,y6);
    l1.display();
    
    l1.addPoint(x6,y6);
    l1.addPoint(x1,y1);
    l1.display();
}


void Hexagon::handleEvent(Event *e)
{
    //Do nothing
}


bool Hexagon::isComplete()
{
    return pointCount == 2;
}


void Hexagon::addPoint(int _x, int _y)
{
    //Don't add to a completed hexagon
    if(isComplete())
    {
        return;
    }

    //Set the points
    if(pointCounter == 0)
    {
        //set the center
        xc = _x;
        yc = _y;
    } else
    {
        //set the corner
        x1 = _x;
        y1 = _y;
    }

    //A point was added
    pointCount ++;
}


