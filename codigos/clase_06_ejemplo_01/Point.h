#ifndef _POINT_H
#define _POINT_H

template <typename T>
class CPoint{
public:
    CPoint();
    CPoint(T x, T y);
    void Move(T dx, T dy);
    T GetX() const;
    T GetY() const;
private:
    T m_x;
    T m_y;
};

#endif