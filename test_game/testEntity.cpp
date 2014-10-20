#include "testEntity.h"
#include <Scene.h>
#include <SceneController.h>
#include <AssetManager.h>
#include <cstdlib>
#include <cmath>



testEntity::testEntity()
    :SceneEntity()
{
    sinVal = 0;
    sinSpeed = (((float)(rand() %100))/100.0f)*0.1;
    startX = rand() %640;
    startY = rand() % 480;
    angle = 0;


}


//Update event
void testEntity::OnUpdate()
{
    sinVal+= sinSpeed;
    SetX(startX+sin(sinVal)*100);
    SetY(startY);
    angle+=3;
}

//Draw event
void testEntity::OnDraw(Renderer* renderer, const Pointf& point)
{
    s2->Draw(renderer,point,5,angle,2.0f,2.0f);
    s->Draw(renderer,point,0,angle);

}

//Initialize
void testEntity::OnInitialize()
{
    s = this->GetScene()->GetSceneController()->GetAssetManager()->LoadSprite("://sprite8.sprbin");
    s2 = this->GetScene()->GetSceneController()->GetAssetManager()->LoadSprite("://talk_button.png");
    this->GetScene()->GetSceneController()->RegisterInputEventHandler(this);
}
