/****************************************************************************
** Meta object code from reading C++ file 'QTWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QTWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTWindow_t {
    QByteArrayData data[7];
    char stringdata[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QTWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QTWindow_t qt_meta_stringdata_QTWindow = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 8),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 9),
QT_MOC_LITERAL(4, 29, 8),
QT_MOC_LITERAL(5, 38, 11),
QT_MOC_LITERAL(6, 50, 9)
    },
    "QTWindow\0OnRender\0\0Renderer*\0renderer\0"
    "renderLater\0renderNow\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x0a,
       6,    0,   33,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QTWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTWindow *_t = static_cast<QTWindow *>(_o);
        switch (_id) {
        case 0: _t->OnRender((*reinterpret_cast< Renderer*(*)>(_a[1]))); break;
        case 1: _t->renderLater(); break;
        case 2: _t->renderNow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QTWindow::*_t)(Renderer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTWindow::OnRender)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QTWindow::staticMetaObject = {
    { &QWindow::staticMetaObject, qt_meta_stringdata_QTWindow.data,
      qt_meta_data_QTWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *QTWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTWindow.stringdata))
        return static_cast<void*>(const_cast< QTWindow*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(const_cast< QTWindow*>(this));
    if (!strcmp(_clname, "DisplayWindow"))
        return static_cast< DisplayWindow*>(const_cast< QTWindow*>(this));
    return QWindow::qt_metacast(_clname);
}

int QTWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QTWindow::OnRender(Renderer * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
