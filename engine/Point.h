#ifndef POINT_H
#define POINT_H

/*
 * Represents a point in 2D space.
 * Author: Brad Triebwasser (04/2014)
 * */

template <class T>
class _Point {
public:
    _Point(T x, T y) : _x(x), _y(y) {}
    inline T X() const{return _x;}
    inline T Y() const {return _y;}
private:
    T _x;
    T _y;
};

typedef _Point<int> Point;      //Integer point
typedef _Point<float> Pointf;   //Float point

#endif // POINT_H
