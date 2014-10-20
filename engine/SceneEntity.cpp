#include "SceneEntity.h"

SceneEntity::SceneEntity()
    :x(0), y(0), parentEntity(NULL), scene(NULL)
{

}

SceneEntity::~SceneEntity()
{

}

//Add a child Entity
void SceneEntity::AddChildEntity(SceneEntity* entity)
{
    children.push_back(entity);
    entity->parentEntity = this;
    entity->OnInitialize();
}

//Get the scene this entity is in
Scene* SceneEntity::GetScene()
{
    return scene;
}
//Set the scene the entity is in
void SceneEntity::SetScene(Scene* scene)
{
    this->scene = scene;
}

//Get the parent scene entity
SceneEntity* SceneEntity::GetParentEntity()
{
    return parentEntity;
}

//Get X position
float SceneEntity::GetX()
{
    return x;
}

//Get Y position
float SceneEntity::GetY()
{
    return y;
}

void SceneEntity::SetX(float x)
{
    this->x = x;
}

//Set y position
void SceneEntity::SetY(float y)
{
    this->y = y;
}

//Update this entity
void SceneEntity::Update()
{
    OnUpdate(); //Call the update event
    for (std::vector<SceneEntity*>::iterator i = children.begin(); i!=children.end(); i++)
        (*i)->Update(); //Update children
}


