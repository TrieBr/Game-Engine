#ifndef QTWINDOW_H
#define QTWINDOW_H

#include "DisplayWindow.h"
#include "QTRenderer.h"
#include <QWindow>
#include <QCloseEvent>
#include <QOpenGLPaintDevice>
#include <QOpenGLFunctions>
#include "QTKeyMap.h"

/*
 * Display Window for the QT back-end.
 * Author: Brad Triebwasser (04/2014)
 * */

class Renderer;
class QTWindow : public QWindow, protected QOpenGLFunctions, public DisplayWindow
{
    Q_OBJECT
public:
    explicit QTWindow(QWindow *parent = 0);
    virtual ~QTWindow();
public slots:
    //Queue a frame to be rendered later
    void renderLater();
    //Render a frame
    void renderNow();
signals:
    //Signal emitted when a frame is to be rendered
    void OnRender(Renderer* renderer);
protected:
    //Events from the window
    bool event(QEvent *event);
    //Expose event
    void exposeEvent(QExposeEvent *event);
    //Key Press Event
    void keyPressEvent(QKeyEvent * ev);
    //Key Release Event
    void keyReleaseEvent(QKeyEvent * ev);
    //Mouse Move Event
    void mouseMoveEvent(QMouseEvent * ev);
    //Mouse Press Event
    void mousePressEvent(QMouseEvent * ev);
    //Mouse Release Event
    void mouseReleaseEvent(QMouseEvent * ev);
    //Touch Event
    void touchEvent(QTouchEvent * ev);

private:
    //Render a frame with QPainter* object
    virtual void render(QPainter *painter);
    //Render a frame (raw OpenGL)
    virtual void render();
private:
    QOpenGLContext *m_context;      //OpenGL Context
    QOpenGLPaintDevice *m_device;   //OpenGL Paint device (for QPainter)
    bool m_update_pending;          //Is an update pending?
    QTKeyMap       inputKeyMap;     //Used to map QT input keycodes to internal engine keycodes
};

#endif // QTWINDOW_H
