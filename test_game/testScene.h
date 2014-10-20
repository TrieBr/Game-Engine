#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <Scene.h>

class testScene : public Scene
{
public:
    testScene();
    virtual void OnRender(Renderer* renderer);
    //Initialize event
    virtual void OnInitialize();

    //Fired when key is pressed
    virtual void OnKeyPressEvent(InputKeyEvent *e);

private:
    std::shared_ptr<Sprite> s;
    float y;
    float x;
};

#endif // TESTSCENE_H
