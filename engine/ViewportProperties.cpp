#include "ViewportProperties.h"

ViewportProperties::ViewportProperties(const Point& portPosition, const Size& portSize,
                                       const Point& viewPosition, const Size& viewSize)
    : portPosition(portPosition), portSize(portSize), viewPosition(viewPosition), viewSize(viewSize)
{

}

Point& ViewportProperties::GetPortPosition()
{
    return portPosition;
}

Size&  ViewportProperties::GetPortSize()
{
    return portSize;
}

Point& ViewportProperties::GetViewPosition()
{
    return viewPosition;
}

Size& ViewportProperties::GetViewSize()
{
    return viewSize;
}
