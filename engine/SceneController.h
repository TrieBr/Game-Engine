#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "ViewportProperties.h"
#include "AssetManager.h"
#include "InputEventHandler.h"
#include "InputEventDispatcher.h"
#include "InputState.h"

/*
 * Handles the updating/rendering of a scene. Contains the handle to the assetManager and Viewport Surface
 * Author: Brad Triebwasser (04/2014)
 * */

class Scene;
class ViewportSurface;
class Viewport;
class Renderer;
class SceneController : public InputEventHandler, public InputEventDispatcher
{
public:
    SceneController();
    ~SceneController();
    //Set the current Scene
    void SetScene(Scene* scene);
    //Set asset Manager
    void SetAssetManager(AssetManager* manager);
    //Get AssetManager
    AssetManager* GetAssetManager();
    //Create a new viewport for this scene
    Viewport* CreateViewport(const ViewportProperties &viewport);
    //Set the viewport surface
    void SetViewportSurface(ViewportSurface* viewportSurface);
    //Get the current input state
    InputState& GetInputState();
    //Update the scene
    void Update();
    //Render the scene
    void Render(Renderer* renderer);

public: //Input Event Handlers
    //Fired when key is pressed
    virtual void OnKeyPressEvent(InputKeyEvent *e);
    //Fired when key is released
    virtual void OnKeyReleaseEvent(InputKeyEvent *e);
    //Fired when mouse button is pressed
    virtual void OnMousePressEvent(InputMouseEvent *e);
    //Fired when mouse button is released
    virtual void OnMouseReleaseEvent(InputMouseEvent *e);
    //Fired when mouse button is moved
    virtual void OnMouseMoveEvent(InputMouseEvent *e);
    //Fired when a touch event (touch begin, touch end, etc.)
    virtual void OnTouchEvent(InputTouchEvent *e);

private:
    Scene*              currentScene;       //Current active scene
    ViewportSurface*    viewportSurface;    //Surface for creating viewports
    AssetManager*       assetManager;       //Asset Manager
    InputState          inputState;         //Current input State
};

#endif // SCENECONTROLLER_H
