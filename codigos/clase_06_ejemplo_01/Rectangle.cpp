#include "Rectangle.h"

template <typename T>
CRectangle<T>::CRectangle()
{

}

template <typename T>
CRectangle<T>::CRectangle(CPoint<T> ptBottomLeft, CPoint<T> ptTopRight)
{
    m_ptBottomLeft = ptBottomLeft;
    m_ptTopRight = ptTopRight;
}

template <typename T>
void CRectangle<T>::Move(T dx, T dy)
{
    m_ptBottomLeft.Move(dx, dy);
    m_ptTopRight.Move(dx, dy);
}

template <typename T>
CPoint<T> CRectangle<T>::GetBottomLeft() const
{
    return m_ptBottomLeft;
}

template <typename T>
CPoint<T> CRectangle<T>::GetTopRight() const
{
    return m_ptTopRight;
}

template <typename T>
T CRectangle<T>::GetWidth() const
{
    return m_ptTopRight.GetX() - m_ptBottomLeft.GetX();
}

template <typename T>
T CRectangle<T>::GetHeight() const
{
    return m_ptTopRight.GetY() - m_ptBottomLeft.GetY();
}

template <typename T>
T CRectangle<T>::GetArea() const
{
  return GetWidth() * GetHeight();
}


template class CRectangle<int>;