#include "Scene.h"
#include "SceneController.h"
#include "Logger.h"
#include "Viewport.h"

Scene::Scene()
    :sceneController(NULL)
{

}

Scene::~Scene()
{
    //Delete entities in this scene
    for ( std::vector<SceneEntity*>::iterator i = entities.begin(); i!=entities.end(); i++) {
        delete (*i);
    }
}

//Add Entity
void Scene::AddEntity(SceneEntity* entity)
{
    entities.push_back(entity);
    entity->SetScene(this);
    entity->OnInitialize();
}

//Add a new viewport to the scene
void Scene::AddViewport(const ViewportProperties &viewport)
{
    Viewport* v = sceneController->CreateViewport(viewport);
    if (v) {
        viewports.push_back(v);
    }
}

//Remove the specified viewport index
void Scene::RemoveViewport(unsigned int index)
{
    if (index>=viewports.size()) return;
    delete viewports.at(index);
    viewports.erase(viewports.begin()+index);
}

//Get the scene controller controlling this scene
SceneController* Scene::GetSceneController()
{
    return sceneController;
}

//Render the viewports to the display
void Scene::RenderViewports(Renderer* renderer)
{
    if (viewports.size()==0) {
        Logger::Warn("Rendering viewports with no viewports added!");
    }
    for (std::vector<Viewport*>::iterator i = viewports.begin(); i!=viewports.end(); i++) {
        (*i)->Render(renderer,this);    //Render this scene in the viewport
        (*i)->Render(renderer,entities);//Render entities in this scene in the viewport
    }

}

//Set the scene controller
void Scene::SetSceneController(SceneController* controller)
{
    sceneController = controller;

}

//Render Scene
void Scene::DoRender(Renderer* renderer)
{
    RenderViewports(renderer);
}

//Perform an update
void Scene::Update()
{
    //Update all entities in the scene
    for (std::vector<SceneEntity*> ::iterator i = entities.begin(); i!=entities.end(); i++) {
        (*i)->Update();
    }
}

//Initialize event
void Scene::OnInitialize()
{

}

//Render Scene
void Scene::OnRender(Renderer* renderer) {
    UNUSED(renderer);
}

