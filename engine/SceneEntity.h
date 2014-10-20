#ifndef SCENEENTITY_H
#define SCENEENTITY_H

#include <vector>
#include "Drawable.h"
#include "Renderer.h"
#include "Sprite.h"
#include "InputEventHandler.h"
#include "InputEventDispatcher.h"
#include <memory>


/*
 * Entity that is placed in a scene (A Game Object).
 * The Entity can have child entities which are drawn relative to the parent.
 * Author: Brad Triebwasser (04/2014)
 * */



class Scene;
class SceneEntity : public Drawable, public InputEventHandler
{
public:
    SceneEntity();
    virtual ~SceneEntity();
    //Add a child Entity
    void AddChildEntity(SceneEntity* entity);
    //Get the scene this entity is in
    Scene* GetScene();
    //Set the scene the entity is in
    void SetScene(Scene* scene);
    //Get the parent scene entity
    SceneEntity* GetParentEntity();
    //Get X position
    float GetX();
    //Get Y position
    float GetY();
    //Set x position
    void SetX(float x);
    //Set y position
    void SetY(float y);
    //Override the Drawable::Draw
    virtual inline void Draw(Renderer* renderer,const Pointf& point) override { OnDraw(renderer,point); }
    //Update this entity
    virtual inline void Update();
public: //Events
    //Update event
    virtual void OnUpdate() {}
    //Draw event
    virtual void OnDraw(Renderer* renderer,const Pointf& point) { UNUSED(renderer); UNUSED(point);}
    //Initialize
    virtual void OnInitialize() {}
private:
    float x;                    //X position (relative to parent)
    float y;                    //Y position (relative to parent)
    std::vector<SceneEntity*>   children;  //Children entities
    SceneEntity* parentEntity;  //Parent scene entity.
    Scene*      scene;          //Scene this entity is in
};

#endif // SCENEENTITY_H
