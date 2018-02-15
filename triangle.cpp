#include <iostream>
#include <iomanip>
#include <cmath>
#include "triangle.h"

using namespace std;

triangle::triangle(){
    //where does it start
    x1 = 0;
    y1 = 0;
    pointCount = 0;
}

void triangle::display(){
            // display the triangle
    if(not iscomplete()){
        return;
    }
     Line 8,9;
    8.addpoint(x1,y1);
    8.display();
    
    9.addpoint(x2,y2);
    9.display();
    
    9.addpoint(x3,y2);
    9.apppoint(-x3,y2)
    9.display();
   

}
void triangle::handleEvent(Event *e){
    //DOES NOTHING
}

bool triangle::iscomplete(){
    return pointCount == 2;
}

void triangle::addpoint(int _x, int _y){
    //if complete
    if(iscomplete()) return;
    
    if(pointCount == 0) {
        x1 =(_x);
        y1 =(_y);
        cout << x1 << "*" << y1 << endl;
    } else if (pointCount == 1) {
        x2 = (_x);
        y2 = (_y);
        cout << x2 << "*" << y2 << endl;
    } else if (pointCounter == 2){
        dy = y2 - y1;
        l = sqrt(2*(pow(dy,2));
        x3 = .5 * l
        cout << x3 << "*" << y2 << endl;
        cout << -x3 << "*" << y2 << endl;
    }
    pointCount++;
}
