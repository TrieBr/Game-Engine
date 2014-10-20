#include "Viewport.h"
#include "Scene.h"

Viewport::Viewport(ViewportSurface* targetSurface, const ViewportProperties& properties)
    :targetSurface(targetSurface), properties(properties)
{

}

//Render specified objects in this viewport
void Viewport::Render(Renderer* renderer, const std::vector<SceneEntity*> &entities)
{
    TransformRenderer(renderer);
    for (std::vector<SceneEntity*>::const_iterator i = entities.begin(); i!=entities.end(); i++) {
        SceneEntity* entity = *i;
        entity->Draw(renderer, Pointf(entity->GetX(),entity->GetY()));
    }
}

//Render scene in this viewport
void Viewport::Render(Renderer* renderer, Scene* scene)
{
    TransformRenderer(renderer);
    scene->OnRender(renderer);
}

//Set the transformations on the renderer for this viewport
void Viewport::TransformRenderer(Renderer* renderer)
{
     renderer->ResetTransform();
     renderer->Translate(Pointf(-(float)properties.GetViewPosition().X(),-(float)properties.GetViewPosition().Y()));
     renderer->SetClipRect(Pointf((float)properties.GetPortPosition().X()+(float)properties.GetViewPosition().X(),(float)properties.GetPortPosition().Y()+(float)properties.GetViewPosition().X()),Sizef((float)properties.GetPortSize().W(),(float)properties.GetPortSize().H()));
     renderer->Scale((float)properties.GetPortSize().W()/(float)properties.GetViewSize().W(),(float)properties.GetPortSize().H()/(float)properties.GetViewSize().H());
     renderer->Translate(Pointf((float)properties.GetPortPosition().X(),(float)properties.GetPortPosition().Y()));
     renderer->Translate(Pointf((float)properties.GetPortPosition().X(),(float)properties.GetPortPosition().Y()));
}
