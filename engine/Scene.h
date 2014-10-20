#ifndef SCENE_H
#define SCENE_H

#include "ViewportProperties.h"
#include <vector>
#include "SceneEntity.h"
#include "Renderer.h"
#include "VirtualFile.h"
#include "SceneController.h"
#include "InputEventHandler.h"
/*
 * Represents a set of Entities (Game objects) and viewports. Handles the updating/rendering of child entities in the Scene.
 * Author: Brad Triebwasser (04/2014)
 * */

class Viewport;
class Scene : public InputEventHandler
{
public:
    Scene();
    virtual ~Scene();
    //Add Entity to the scene
    void AddEntity(SceneEntity* entity);
    //Add a new viewport to the scene
    void AddViewport(const ViewportProperties &viewport);
    //Remove the specified viewport index
    void RemoveViewport(unsigned int index);
    //Get the scene controller controlling this scene
    SceneController* GetSceneController();
    //Render Scene
    void DoRender(Renderer* renderer);
    //Update scene
    void Update();

public: //Events
    //Initialize event
    virtual void OnInitialize();
    //Render Scene event
    virtual void OnRender(Renderer* renderer);
private:
    //Render the viewports to the display
    void RenderViewports(Renderer* renderer);
    //Set the scene controller
    void SetSceneController(SceneController* controller);
    friend class SceneController;       //Only SceneController can call SetSceneController()
private:
    std::vector<SceneEntity*>        entities;          //List of entities in the room
    std::vector<Viewport*>           viewports;         //List of viewports for the scene
    SceneController*                 sceneController;   //SceneController controlling this scene
};

#endif // SCENE_H
