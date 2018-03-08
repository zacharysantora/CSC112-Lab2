// A widget which paints a canvas on the screen.  This canvas will allow us
// to draw shapes in the terminal window.
#ifndef CANVAS_H
#define CANVAS_H
#include "application.h"
#include "widget.h"
#include "shape.h"
#include "term.h"
#include <vector>
#include <iostream>

class Canvas : public Widget
{
public:
    //constructors
    Canvas();

    //required widget function
    virtual void display();
    virtual void handleEvent(Event *e);

    //some parenting magic
    virtual void parent(Widget *_parent);

    //cursor movement commands
    virtual void cursorUp();
    virtual void cursorDown();
    virtual void cursorLeft();
    virtual void cursorRight();
    virtual void cursorAddPoint();
    virtual void colorShape ();
protected:
    int cx, cy;     //cursor position
    std::vector<Shape*> shapeList;
    std::vector<int> colorList;
    Shape *working;  //the shape we are working on
    int choice;
};
#endif
