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

template <typename T>
CPoint<T>::CPoint(){
    m_x = 0;
    m_y = 0;
}

template <typename T>
CPoint<T>::CPoint(T x, T y){
    m_x = x;
    m_y = y;
}

template <typename T>
void CPoint<T>::Move(T dx, T dy)
{
    m_x += dx;
    m_y += dy;
}

template <typename T>
T CPoint<T>::GetX() const{
    return m_x;
}

template <typename T>
T CPoint<T>::GetY() const{
    return m_y;
}

#endif