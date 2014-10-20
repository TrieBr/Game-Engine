#include "testScene.h"
#include "testEntity.h"

#include <AudioStreamOggVorbis.h>
#include <QTAudioVoice.h>
#include <RingBuffer.h>

testScene::testScene()
{
    y  = 0;
    x = 0;
}

void testScene::OnRender(Renderer* renderer)
{

    if (GetSceneController()->GetInputState().KeyIsDown(KeyCode::Key_Up)) {
        y--;
    }
    if (GetSceneController()->GetInputState().KeyIsDown(KeyCode::Key_Down)) {
        y++;
    }
    if (GetSceneController()->GetInputState().KeyIsDown(KeyCode::Key_Left)) {
        x--;
    }
    if (GetSceneController()->GetInputState().KeyIsDown(KeyCode::Key_Right)) {
        x++;
    }

   // renderer->DrawFilledRectangle(Pointf(0,0),Sizef(640,480),Color(192,239,168));
    this->::Scene::OnRender(renderer);
    s->Draw(renderer,Pointf(x,y));
}

void testScene::OnInitialize() {
    this->AddViewport(ViewportProperties(Point(0,0),Size(640,480),Point(0,0),Size(320,240)));
    for (int i=0; i<50; i++){
        this->AddEntity(new testEntity());
    }
    s = this->GetSceneController()->GetAssetManager()->LoadSprite("://fenrir.png");
   // VirtualFile* f = this->GetSceneController()->GetAssetManager()->FetchAsset(":omg.png");

    AudioStreamOggVorbis *vorbisStream = new AudioStreamOggVorbis();
    vorbisStream->Open(this->GetSceneController()->GetAssetManager()->FetchVirtualFile(":/new/prefix1/assets/test.ogg"));
    QTAudioVoice *voice = new QTAudioVoice();
    voice->AttachAudioStream(vorbisStream);


}


//Fired when key is pressed
void testScene::OnKeyPressEvent(InputKeyEvent *e) {


}
