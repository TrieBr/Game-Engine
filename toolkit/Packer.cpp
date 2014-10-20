#include "Packer.h"
#include <cstdlib>


Packer::Packer()
{
    rc = Rectangle(0,0,0,0);
    leaf = true;
    occupied = false;
}
//Create a new packing rectangle of specified dimensions
Packer::Packer(int width, int height)
{
    rc = Rectangle(0,0,width,height);
    leaf = true;
    occupied = false;
}

//Insert a Packer rectangle into this one
Packer* Packer::Insert(const Rectangle& rect)
{
    Packer* n = InsertOp(rect);
    if (n) {
        n->occupied = true;
    }
    return n;
}

//Insert operation
Packer* Packer::InsertOp(const Rectangle& rect)
{
        if (!leaf) { //try inserting into first child if we are not a leaf
            Packer* newNode = child[0]->InsertOp(rect);
            if (newNode) return newNode;
            child[1]->InsertOp(rect);
        }else{
            if (occupied) return NULL;

            //if we're too small, return
            if (rect.Width()>rc.Width() || rect.Height()>rc.Height()) //doesn't fit in pnode->rect
                return NULL;

            //if we're just right, accept
            if (rect.Width()==rc.Width() && rect.Height()==rc.Height())// img fits perfectly in pnode->rect
                return this;

            //Split and create children
            leaf = false;
            child[0] = new Packer();
            child[1] = new Packer();

            //decide whichspriteElemspriteElementto split
            int dw = rc.Width() - rect.Width();
            int dh = rc.Height() - rect.Height();

            if (dw > dh) {
                child[0]->rc = Rectangle(rc.Left(), rc.Top(),
                                           rc.Left()+rect.Width(), rc.Bottom());
                child[1]->rc = Rectangle(rc.Left()+rect.Width(), rc.Top(),
                                           rc.Right(), rc.Bottom());
            }else{
                child[0]->rc = Rectangle(rc.Left(), rc.Top(),
                                           rc.Right(), rc.Top()+rect.Height());
                child[1]->rc = Rectangle(rc.Left(), rc.Top()+rect.Height(),
                                           rc.Right(), rc.Bottom());

            }
            //insert into first child we created
            return child[0]->InsertOp(rect);
        }

}
