#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Point.h"

template <typename T>
class CRectangle{
public:
    CRectangle();
    CRectangle(CPoint<T> ptBottomLeft, CPoint<T> ptTopRight);
    void Move(T dx, T dy);
    CPoint<T> GetBottomLeft() const;
    CPoint<T> GetTopRight() const;
    T GetWidth() const;
    T GetHeight() const;
    T GetArea() const;
private:
    CPoint<T> m_ptBottomLeft;
    CPoint<T> m_ptTopRight;
};

#endif