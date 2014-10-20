#ifndef QTKEYMAP_H
#define QTKEYMAP_H

#include <Qt>
#include <map>
#include "InputKeyEvent.h"
#include <QKeyEvent>


/*
 * This class is used to map QT Key events to internal key events. Since QT uses different KeyCodes and KeyModifiers, we need to restructure the event into our internal InputKeyEvent
 *
 * */

class QTKeyMap
{
public:
    QTKeyMap();
    //Initialize the map
    void Initialize();
    //Convert a QT Key event to the internal format
    InputKeyEvent ConvertToInternalKeyEvent(QKeyEvent* ev);

private:
    std::map<int,KeyCode> keyMap; //Map of QT Keys to internal KeyCode keys
};

#endif // QTKEYMAP_H
