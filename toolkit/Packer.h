#ifndef PACKER_H
#define PACKER_H

#include "Rectangle.h"

class Packer
{
public:
    Packer();
    //create a new packing rectangle of specified dimensions
    Packer(int width, int height);
    //insert a Packer rectangle into this one
    Packer* Insert(const Rectangle& rect);
    //Get the rect for this packing rectanlge
    Rectangle GetRect() { return rc; }
private:
    //Insert operation
    Packer* InsertOp(const Rectangle& rect);
private:
    bool  leaf;         //Is this Packer a leaf node in the tree?
    Packer* child[2];   //Pointers to children
    Rectangle rc;       //Rectangle for this node
    bool occupied;      //Is this spot occupied already
};



#endif // PACKER_H
