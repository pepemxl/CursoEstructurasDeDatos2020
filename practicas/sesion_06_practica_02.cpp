#include <stdio.h>

int fun();
int fun2();

class CPoint{
public:
    void SetX(int );
    int GetX();
private:
    int x;
    int y;
};

int CPoint::GetX(){

    return x;
}

void CPoint::SetX(int _x){
    this->x = _x;
}

int main(int argc, char *argv[]){
    //int x = fun();
    CPoint p1;
    printf("%d\n",fun2());
    p1.SetX(3) ;
    printf("%d\n",p1.GetX());
    return 0;
}

int fun2(){
    return 5;
}

