#include <cstdlib>
#include "Engine.h"
#include "DisplayWindow.h"
#include "AssetManager.h"

Engine::Engine()
    : window(NULL), assetManager(NULL), sceneController(NULL),   terminate_loop(false)
{
}

Engine::~Engine()
{
  Shutdown();
}


void Engine::Start()
{
    engineStartTime = std::chrono::high_resolution_clock::now();
}

//Initialize
void Engine::Initialize()
{
    sceneController = new SceneController();
    sceneController->SetViewportSurface(window);
}

//Get scene controller
SceneController* Engine::GetSceneController()
{
    return sceneController;
}

unsigned int Engine::GetElapsedMilliseconds()
{
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds m = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - engineStartTime);
    return (unsigned int)m.count();
}

void Engine::Shutdown()
{
    if (sceneController) {
        delete sceneController;
        sceneController = NULL;
    }
    if (assetManager){
        delete assetManager;
        assetManager = NULL;
    }
}

void Engine::ProcessEvents()
{

}

void Engine::Update()
{
   const int TICKS_PER_SECOND = 30;
   const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
   const int MAX_FRAMESKIP = 10;
   static unsigned next_game_tick = GetElapsedMilliseconds();
   int loops = 0;
   while(GetElapsedMilliseconds() > next_game_tick && loops < MAX_FRAMESKIP) {
       ProcessEvents();
       sceneController->Update();
       next_game_tick += SKIP_TICKS;
       loops++;
   }
}

void Engine::Render(Renderer* renderer)
{
    sceneController->Render(renderer);
}



