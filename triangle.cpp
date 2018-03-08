-#include <iostream>
#include <iomanip>
#include <cmath>
#include "triangle.h"

using namespace std;

triangle::triangle(){
    //where does it start
    x1 = 0;
    y1 = 0;
    x3 = 0;
    x4 = 0;
    pointCount = 0;
}

void triangle::display(){
            // display the triangle
    if(not iscomplete()){
        return;
    }
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
        if (x1!=x2){
            cout << "pick another point" << endl;
        }
        x2 = (_x);
        y2 = (_y);
        cout << x2 << "*" << y2 << endl;
        dy = y2 - y1;
        l = sqrt(2*(pow(dy,2)));
        x3 = .5 * l
        cout << x3 << "*" << y2 << endl;
        cout << x4 << "*" << y2 << endl;
                 }
    pointCount++;
}
