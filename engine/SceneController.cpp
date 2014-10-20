#include "SceneController.h"
#include "Scene.h"
#include "ViewportSurface.h"
#include "Logger.h"

SceneController::SceneController()
    :currentScene(NULL), viewportSurface(NULL), assetManager(NULL)
{
    RegisterInputEventHandler(&inputState);
}
SceneController::~SceneController()
{
   if (currentScene) delete currentScene;
}

//Set the current Scene
void SceneController::SetScene(Scene* scene)
{
    if (currentScene) {
        UnregisterInputEventHandler(currentScene);
        delete currentScene;
    }
    currentScene = scene;
    RegisterInputEventHandler(currentScene); //The Scene should subscribe to input events dispatched by this scebe controller
    currentScene->SetSceneController(this);
    currentScene->OnInitialize();
}

//Set asset Manager
void SceneController::SetAssetManager(AssetManager* manager)
{
    assetManager = manager;
}

//Get AssetManager
AssetManager* SceneController::GetAssetManager()
{
    return assetManager;
}

//Create a new viewport for this scene
Viewport* SceneController::CreateViewport(const ViewportProperties &viewport)
{
    if (!viewportSurface) {
        Logger::Warn("SceneController cannot create viewport with NULL viewportSurface.");
        return NULL;
    }
    return viewportSurface->CreateViewport(viewport);
}

//Set the viewport surface
void SceneController::SetViewportSurface(ViewportSurface* viewportSurface)
{
    this->viewportSurface = viewportSurface;
}

//Get the current input state
InputState& SceneController::GetInputState()
{
    return inputState;
}


//Update the scene
void SceneController::Update()
{
    if (currentScene)
        currentScene->Update();
}

//Update the scene
void SceneController::Render(Renderer* renderer)
{
    if (currentScene)
        currentScene->DoRender(renderer);
}


//Fired when key is pressed
void SceneController::OnKeyPressEvent(InputKeyEvent *e)
{
    this->DispatchKeyPressEvent(e); //Dispatch to all subscribers
}

//Fired when key is released
void SceneController::OnKeyReleaseEvent(InputKeyEvent *e)
{
    this->DispatchKeyReleaseEvent(e); //Dispatch to all subscribers
}

//Fired when mouse button is pressed
void SceneController::OnMousePressEvent(InputMouseEvent *e)
{
    this->DispatchMousePressEvent(e); //Dispatch to all subscribers
}

//Fired when mouse button is released
void SceneController::OnMouseReleaseEvent(InputMouseEvent *e)
{
    this->DispatchMouseReleaseEvent(e); //Dispatch to all subscribers
}

//Fired when mouse button is moved
void SceneController::OnMouseMoveEvent(InputMouseEvent *e)
{
    this->DispatchMouseMoveEvent(e); //Dispatch to all subscribers
}

//Fired when a touch event (touch begin, touch end, etc.)
void SceneController::OnTouchEvent(InputTouchEvent *e)
{
    this->DispatchTouchEvent(e); //Dispatch to all subscribers
}



