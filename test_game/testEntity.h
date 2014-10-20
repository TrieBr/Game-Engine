#ifndef TESTENTITY_H
#define TESTENTITY_H

#include <SceneEntity.h>


class testEntity : public SceneEntity
{
public:
    testEntity();
    //Update event
    virtual void OnUpdate();
    //Draw event
    virtual void OnDraw(Renderer* renderer,const Pointf& point);
    //Initialize
    virtual void OnInitialize();

private:
    double sinVal;
    double sinSpeed;
    double startX;
    double startY;
    double angle;
    std::shared_ptr<Sprite> s;
    std::shared_ptr<Sprite> s2;
};

#endif // TESTENTITY_H
