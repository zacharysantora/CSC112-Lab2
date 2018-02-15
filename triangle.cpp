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
<<<<<<< HEAD
    x1 = 0;
    y1 = 0;
    x3 = 0;
    x4 = 0;
=======
    x1 = -1;
    y1 = -1;
>>>>>>> 34f3536af836f8d3a029cf0cf41e3e9588762993
    pointCount = 0;
}

void triangle::display(){
            // display the triangle
    if(not isComplete()){
        return;
    }
<<<<<<< HEAD
    c=2*(y2-y1);
    x3=x2+c;
    x4=x2-c;
     Line a,b,c;
    a.addpoint(x1,y1);
    a.display();
    
    b.addpoint(x2,y2);
    b.display();
    
    b.addpoint(x3,y2);
    b.apppoint(x4,y2);
    b.display();
    
    c.addpoint(x1,y1);
    c.display();
=======
    
     Line l1,l2;
    l1.addPoint(x1,y1);
    l1.display();
    
    l2.addPoint(x2,y2);
    l2.display();
    
    l2.addPoint(x3,y2);
    l2.addPoint(-x3,y2);
    l2.display();
   
>>>>>>> 34f3536af836f8d3a029cf0cf41e3e9588762993

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
<<<<<<< HEAD
        if (x1!=x2){
            cout << "pick another point" << endl;
        }
        x2 = (_x);
        y2 = (_y);
        cout << x2 << "*" << y2 << endl;
        dy = y2 - y1;
        l = sqrt(2*(pow(dy,2)));
        x3 = .5 * l
=======
        x2 = _x;
        y2 = _y;
        cout << x2 << "*" << y2 << endl;
    } else if (pointCount == 2) {
        dy = y2 - y1;
        l = sqrt(2*(pow(dy,2)));
        x3 = .5 * l;
>>>>>>> 34f3536af836f8d3a029cf0cf41e3e9588762993
        cout << x3 << "*" << y2 << endl;
        cout << x4 << "*" << y2 << endl;
                 }
    pointCount++;
}
