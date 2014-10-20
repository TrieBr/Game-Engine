#ifndef ENGINE_H
#define ENGINE_H

#include "SceneController.h"
#include <chrono>


/*
 * Main Engine that controls the game loop and other main components.
 * Author: Brad Triebwasser (04/2014)
 * */

class AssetManager;
class DisplayWindow;
class Renderer;
class Engine
{
public:
    Engine();
    ~Engine();
    //Start the engine
    virtual void Start();
    //Initialize
    virtual void Initialize();
    //Get scene controller
    SceneController* GetSceneController();
public:
    //Get number of Milliseconds elapsed since engine started
    unsigned int GetElapsedMilliseconds();
protected:
    //Shutdown/cleanup the engne
    virtual void Shutdown();
    //Process events (Input, etc)
    virtual void ProcessEvents();
    //Update Step
    virtual void Update();
    //Render step
    virtual void Render(Renderer* renderer);
protected:
    DisplayWindow*      window;             //Window displaying the game
    AssetManager*       assetManager;       //Asset manager
    SceneController*    sceneController;    //The scene controller
    bool                terminate_loop;     //Flag to terminate the game loop
    std::chrono::high_resolution_clock::time_point        engineStartTime;    //Time the engine started

};

#endif // ENGINE_H
