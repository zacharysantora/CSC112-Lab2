class Rectangle : public Shape
{
public:

Rectangle(); //public constuctor

virtual void addPoint(int_x, int_y);


virtual void display();
virtual void handleEvent(Event *e);

virtual bool isComplete();

private:


int x1,y1;
int x2,y2
int pointCount;
};
#endif