#include <iostream>
#include "Point.h"
#include "Rectangle.h"


int main(int argc, char *argv[]){
    int x, y;
    x = 2;
    y = 1;
    std::cout << "El punto P1: (" << x << "," << y << ")" << std::endl;

    CPoint<int> p1(x, y);

    p1.Move(3, 5);
    std::cout << "Movemos punto (3,5) entonces p1 = (" << p1.GetX() << ", " << p1.GetY() << ")"<< std::endl;
    x = 8;
    y = 8;

    CPoint<int> p2(x, y);
    std::cout << "El punto P2: (" << x << "," << y << ")" << std::endl;
    CRectangle<int> r(p1, p2);
    std::cout << "El area del rectangulo definido por P1 y P2 es: " << r.GetArea() << std::endl;

    CPoint<float> P3;
    return 0;
}