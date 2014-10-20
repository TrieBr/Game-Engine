#include "QTWindow.h"
#include <QPainter>
#include <QCoreApplication>
#include <QGuiApplication>
#include "Logger.h"
#include "InputKeyEvent.h"
#include "InputMouseEvent.h"
#include "InputTouchEvent.h"


QTWindow::QTWindow(QWindow *parent)
    :QWindow(parent), DisplayWindow(), m_context(0), m_device(0), m_update_pending(false)
{
    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
        format.setSamples(0);
        format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    setFormat(format);
    resize(640,480);
    inputKeyMap.Initialize();
}

QTWindow::~QTWindow()
{

}


void QTWindow::render()
{
    if (!m_device)
        m_device = new QOpenGLPaintDevice;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    m_device->setSize(size());
    QPainter painter(m_device); //Create the painter on the OpenGLPaintDevice
    painter.setRenderHint(QPainter::Antialiasing,false);    //Turn off antialiasing
    QTRenderer renderer(&painter);  //Create a QTRenderer object
    render(&painter);   //Render
    emit OnRender(&renderer);   //Emit render signal
}

void QTWindow::render(QPainter *painter)
{
    //Clear to color
    painter->fillRect(0,0,size().width(),size().height(),QBrush(QColor(64,64,64)));
}

void QTWindow::renderLater()
{
   if (!m_update_pending) {
       m_update_pending = true;
      QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

void QTWindow::renderNow()
{
    if (!isExposed())
        return;

    if (!m_context) {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();
    }

    m_context->makeCurrent(this);   //Make the context the current one
    render();   //Render
    m_context->swapBuffers(this); //Swap back buffer
    renderLater();  //Queue another frame to be rendered
}

bool QTWindow::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::UpdateRequest:
        m_update_pending = false;
        renderNow();
        return true;
    default:
        return QWindow::event(event);
    }
}


void QTWindow::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);
    if (isExposed())
        renderNow();
}


//Key Press Event
void QTWindow::keyPressEvent(QKeyEvent * ev)
{
    InputKeyEvent keyEvent = inputKeyMap.ConvertToInternalKeyEvent(ev);
    this->DispatchKeyPressEvent(&keyEvent);
}

//Key Release Event
void QTWindow::keyReleaseEvent(QKeyEvent * ev)
{
    InputKeyEvent keyEvent = inputKeyMap.ConvertToInternalKeyEvent(ev);
    this->DispatchKeyReleaseEvent(&keyEvent);
}

//Mouse Move Event
void QTWindow::mouseMoveEvent(QMouseEvent * ev)
{

}

//Mouse Press Event
void QTWindow::mousePressEvent(QMouseEvent * ev)
{

}

//Mouse Release Event
void QTWindow::mouseReleaseEvent(QMouseEvent * ev)
{

}

//Touch Event
void QTWindow::touchEvent(QTouchEvent * ev)
{

}


