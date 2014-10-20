#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>

class Rectangle
{
public:
    Rectangle();
    Rectangle(int x1, int y1, int x2, int y2);
    int Left() const{ return x1; }
    int Top() const{ return y1; }
    int Right() const{ return x2; }
    int Bottom() const{ return y2; }
    int Width() const{ return x2-x1; }
    int Height() const{ return y2-y1; }
private:
    int x1;
    int y1;
    int x2;
    int y2;
};

#endif // RECTANGLE_H
