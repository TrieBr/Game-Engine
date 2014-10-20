#include <Logger.h>
#include <QTEngine.h>
#include "testScene.h"



int main(int argc, char** argv) {


    QTEngine t(argc,argv);
    t.Initialize();
    t.GetSceneController()->SetScene(new testScene());

    t.Start();
    return 0;
}
