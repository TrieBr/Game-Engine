#ifndef QTENGINE_H
#define QTENGINE_H

#include "QTWindow.h"
#include "Engine.h"
#include <QGuiApplication>
#include <QTimer>

/*
 * Engine for the QT back-end.
 * Author: Brad Triebwasser (04/2014)
 * */

class Renderer;
class QTEngine : public QObject, public Engine
{
    Q_OBJECT
public:
    QTEngine(int &argc, char **argv);
    ~QTEngine();
    //Start the engine (Overrides Engine::Start())
    virtual void Start()  override;
    //Initialize (Overrides Engine::Initialize())
    virtual void Initialize() override;
protected:
    //Shutdown (Overrides Engine::Shutdown())
    virtual void Shutdown() override;
    //Processes events (Overrides Engine::ProcessEvents())
    virtual void ProcessEvents() override;
public slots:
    //Slot for when the window signals a render
    void OnWindowRender(Renderer* renderer);
    //Called when the QTimer fires to perform an update tick
    void OnTick();
private:
    QGuiApplication* app;       //QT Gui Application
    QTWindow* win;              //QT Window
    int& argc;                  //Argc from original commandline (required for QGuiApplication)
    char**argv;                 //Argv from original commandline (required for QGuiApplication)
    QTimer* updateTimer;        //Timer used to fire updates
};

#endif // QTENGINE_H
