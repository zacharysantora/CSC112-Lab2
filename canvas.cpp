// A widget which paints a canvas on the screen.  This canvas will allow us
// to draw shapes in the terminal window.
#include <iostream>
#include "canvas.h"
#include "term.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "hexagon.h"
#include "sierpinski.h"
#include "quadrangle.h"
#include "rectangle.h"

using namespace std;

// constructors
Canvas::Canvas()
{
    colorShape();
	x(1);
	y(1);
	this->cx = 1;
	this->cy = 1;
    // initailly have no working shape
    working = nullptr;
}


// required widget function
void 
Canvas::display()
{
   ostream& (*array[8]) (ostream&) = {white, black, cyan, magenta, yellow, green, blue, red};
     // display the shapes
    for(int i = 0; i < shapeList.size(); i++) {
	    cout << array[colorList[i]];
        shapeList[i]->display();
    }
    cout << cursorPosition(0,2) << "Pick a color for the shape: " << endl;
    cout << cursorPosition(2,3) << "0. White " << endl;
    cout << cursorPosition(2,4) << "1. Black " << endl;
    cout << cursorPosition(2,5) << "2. Cyan " << endl;
    cout << cursorPosition(2,6) << "3. Magenta " << endl;
    cout << cursorPosition(2,7) << "4. Yellow " << endl;
    cout << cursorPosition(2,8) << "5. Green " << endl;
    cout << cursorPosition(2,9) << "6. Blue " << endl;
    cout << cursorPosition(2,10) << "7. Red " << endl;
    cout << cursorPosition(100,70) << "(P)oint (L)ine (R)ectangle (Q)uadrangle (T)riangle (H)exagon (S)ierpinski";
    cout << cursorPosition(cx, cy)  << '+';
    cout.flush();
}
   
void Canvas::colorShape (){
   ostream& (*array[8]) (ostream&) = {white, black, cyan, magenta, yellow, green, blue, red};
    
    cout << cursorPosition(0,2) << "Pick a color for the shape: \n";
    cout << cursorPosition(2,3) << "0. White \n";
    cout << cursorPosition(2,4) << "1. Black \n";
    cout << cursorPosition(2,5) << "2. Cyan \n";
    cout << cursorPosition(2,6) << "3. Magenta \n";
    cout << cursorPosition(2,7) << "4. Yellow \n";
    cout << cursorPosition(2,8) << "5. Green \n";
    cout << cursorPosition(2,9) << "6. Blue \n";
    cout << cursorPosition(2,10) << "7. Red \n";
            cin >> choice;
     if(choice>=0 and choice<8){
           colorList.push_back(choice);
           cout << array[choice] << endl;
     }
}

void
Canvas::handleEvent(Event *e) 
{
   ostream& (*array[8]) (ostream&) = {white, black, cyan, magenta, yellow, green, blue, red};
    
    KeyboardEvent *kb;

    if(e->type() == "keyboard") {
	kb = (KeyboardEvent*) e;
	switch(kb->key()) {
	case UP:
	    cursorUp();
	    break;
	case DOWN:
	    cursorDown();
	    break;
	case LEFT:
	    cursorLeft();
	    break;
	case RIGHT:
	    cursorRight();
	    break;
	case ENTER:
	    cursorAddPoint();
	    break;
   
        case '0':
            if(working == nullptr){
                cout << white;
                colorList.push_back(0);
            }
            break;
        case '1':
            if(working == nullptr){
                cout << black;
                colorList.push_back(1);
            }
            break;
        case '2':
            if(working == nullptr){
                cout << cyan;
                colorList.push_back(2);
            }
            break;
        case'3':
            if(working == nullptr){
                cout << magenta;
                colorList.push_back(3);
            }
            break;
        case '4':
            if(working == nullptr){
                cout << yellow;
                colorList.push_back(4);
            }
            break;
        case '5':
            if(working == nullptr){
                cout << green;
                colorList.push_back(5);
            }
            break;
        case '6':
            if(working == nullptr){
                cout << blue;
                colorList.push_back(6);
            }
            break;
        case '7':
            if(working == nullptr){
                cout << red;
                colorList.push_back(7);
            }
            break;
            
    case 'h':
	case 'H':
	    if(working == nullptr) {
		working = new Hexagon();
		cursorAddPoint();
                cout << cursorPosition(0,0) << clearLine << "Hexagon:" << "/4" << endl;
        }
	    break;
	case 'q':
	case 'Q':
	    if(working == nullptr) {
		working = new Quadrangle();
		cursorAddPoint();
            cout << cursorPosition(0,0) << clearLine << "Quadrangle:" << endl;
	    }
	    break;
	case 'r':
	case 'R':
	    if(working == nullptr) {
		working = new Rectangle();
		cursorAddPoint();
            cout << cursorPosition(0,0) << clearLine << "Rectangle" << endl;
        }
	    break;
	case 's':
	case 'S':
	    if(working==nullptr) {
		working = new Sierpinski();
		cursorAddPoint();
            cout << cursorPosition(0,0) << clearLine << "Sierpinski" << endl;
	    }
	    break;
	case 't':
	case 'T':
	    if(working==nullptr) {
		working = new triangle();
		cursorAddPoint();
            cout << cursorPosition(0,0) << clearLine << "Triangle:" << "/2" << endl;
	    }
	    break;
	case 'p':
	case 'P':
	    if(working == nullptr) {
		working = new Point();
		cursorAddPoint();
            cout << cursorPosition(0,0) << clearLine << "Point" << normal << endl;
	    }
	    break;
	case 'l':
	case 'L':
	    if(working == nullptr) {
		working = new Line();
		cursorAddPoint();
            cout << cursorPosition(0,0) << clearLine << "Line" << normal << endl;
	    }
	    break;
	case ESC:
	    if(_parent) ((Application*)_parent)->running(false);
	    break;
    }
	display();
    }
}

//some parenting magic
void
Canvas::parent(Widget *_parent)
{
    Widget::parent(_parent);

    if(_parent) {
        //copy width and height
        width(_parent->width());
        height(_parent->height());

        //put cursor in the middle
        cout << cursorPosition(cx, cy) << ' ';
        cx = width()/2+1;
        cy = height()/2+1;
        display();
    }
}



// cursor movement commands
void 
Canvas::cursorUp()
{
    // clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    // move the cursor
    cy--;
    if(cy<1) cy=1;
}


void
Canvas::cursorDown()
{
    // clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    // move the cursor
    cy++;
    if(cy>height()) cy=height();
}


void
Canvas::cursorLeft()
{
    // clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    // move the cursor
    cx--;
    if(cx<1) cx=1;
}


void
Canvas::cursorRight()
{
    // clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    // move the cursor
    cx++;
    if(cx>width()) cx=width();
}


void
Canvas::cursorAddPoint()
{
    // if there is no working shape, return
    if(working == nullptr) return;

    // add to the shape
    working->addPoint(cx, cy);
 
    // if the shape is complete, add it to the list
    if(working->isComplete()) {
        shapeList.push_back(working);
        working = nullptr;  // get ready for the next shape
    }
}
