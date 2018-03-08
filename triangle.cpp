#include <iostream>
#include <iomanip>
#include <cmath>
#include "triangle.h"
#include "shape.h"
#include "term.h"
#include "line.h"

using namespace std;

triangle::triangle(){
    //where does it start
    
    _x = -1;
    _y = -1;
    pointCount = 0;
}

void triangle::display(){
            // display the triangle
    if(not isComplete()){
        return;
    }

     Line l1,l2,l3,l4,l5;

    c=2*(y2-y1);
    x3=x2+c;
    x4=x2-c;
    
    l1.addPoint(x1,y1);
    l1.display();

    l2.addPoint(x2,y2);
    l3.addPoint(x3,y2);
    l3.addPoint(x4,y2);
    l2.display();

    l2.addPoint(x3,y2);
    l2.addPoint(-x3,y2);
    l2.display();

    l3.addPoint(x3,y2);
    l3.addPoint(x4,y2);
    l3.addPoint(x1,y1);
    l3.display();
    
    l4.addPoint(x4,y2);
    l4.addPoint(x1,y1);
    l4.display();
    
    l5.addPoint(x3,y2);
    l5.addPoint(x1,y1);
    l5.display();
}
void triangle::handleEvent(Event *e){
    //DOES NOTHING
}

bool triangle::isComplete(){
    return pointCount == 2;
}

void triangle::addPoint(int _x, int _y){
    //if complete
    if(isComplete()) return;
    
    if(pointCount == 0) {
        x1 = _x;
        y1 = _y;
        pointCount++;

    } else if (pointCount == 1) {
        x2 = _x;
        y2 = _y;
        pointCount++;

    } else if (pointCount == 2) {
        x3 = _x;
        y2 = _y;
        x4 = _x;

    pointCount++;
 }
}