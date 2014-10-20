#ifndef SIZE_H
#define SIZE_H

/*
 * Represents a 2-Dimensional size.
 * Author: Brad Triebwasser (04/2014)
 * */

template <class T>
class _Size {
public:
    _Size(T w, T h) : _w(w), _h(h) { }
    inline T W() const{return _w;}
    inline  T H() const{return _h;}
private:
    T _w;
    T _h;
};

typedef _Size<int> Size;        //Integer size
typedef _Size<float> Sizef ;    //Float size


#endif // SIZE_H
