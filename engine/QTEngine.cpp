#include "QTEngine.h"
#include "SceneController.h"
#include "QTAssetManager.h"



QTEngine::QTEngine(int &argc, char **argv)
    :Engine(), argc(argc), argv(argv), updateTimer(NULL)
{

}


QTEngine::~QTEngine()
{

}

void QTEngine::Start()
{
    this->Engine::Start();
    updateTimer = new QTimer(this);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(OnTick()));
    updateTimer->start(0);
    app->exec();    //This will return when the QGuiApplication app (window) is closed
    Shutdown();
}

void QTEngine::Initialize()
{

    app = new QGuiApplication(argc, argv);
    QTWindow* win = new QTWindow(); //Create the new QT Window
    win->show();    //Show the window
    window = win;
    connect(win,SIGNAL(OnRender(Renderer*)),this,SLOT(OnWindowRender(Renderer*)));    //Connect the window's render signal with this OnWindowRender Slot
    this->Engine::Initialize(); //Initialize the engine
    assetManager = new QTAssetManager(); //Create an asset manager
    sceneController->SetAssetManager(assetManager); //Set the asset manager for the scene controller
    window->RegisterInputEventHandler(sceneController); //Register the scene controller to receive input events from the window
}

void QTEngine::Shutdown()
{
    if (updateTimer) delete updateTimer;
    delete window;
    this->Engine::Shutdown();
}


void QTEngine::ProcessEvents()
{
    this->Engine::ProcessEvents();
}

void QTEngine::OnWindowRender(Renderer* renderer)
{
    Render(renderer);
}

void QTEngine::OnTick()
{
    Update();
}
