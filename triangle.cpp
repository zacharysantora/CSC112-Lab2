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
    x1 = -1;
    y1 = -1;
    pointCount = 0;
}

void triangle::display(){
            // display the triangle
    if(not isComplete()){
        return;
    }
    
     Line l1,l2;
    l1.addPoint(x1,y1);
    l1.display();
    
    l2.addPoint(x2,y2);
    l2.display();
    
    l2.addPoint(x3,y2);
    l2.addPoint(-x3,y2);
    l2.display();
   

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
        x1 =_x;
        y1 =_y;
        cout << x1 << "*" << y1 << endl;
    } else if (pointCount == 1) {
        x2 = _x;
        y2 = _y;
        cout << x2 << "*" << y2 << endl;
    } else if (pointCount == 2) {
        dy = y2 - y1;
        l = sqrt(2*(pow(dy,2)));
        x3 = .5 * l;
        cout << x3 << "*" << y2 << endl;
        cout << -x3 << "*" << y2 << endl;
    }
    pointCount++;
}
