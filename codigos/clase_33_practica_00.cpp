#include <iostream>
#include <memory>
#include <string> 
 
/* estructura de datos dummy para ejemplo de manejo de memoria */

class Foo{
public:
    int id;
    static int counter;
    Foo(){
        counter++;
        id = counter;
        std::cout << "Foo::Foo instancia:" << id << std::endl;  
    }
    ~Foo(){ 
        std::cout << "Foo::~Foo instancia:" << id << std::endl; 
    }
    void bar() { 
        std::cout << "Foo::bar instancia:" << id  << std::endl;  
    }
};

void f(const Foo &p){
    std::cout << "f(const Foo&)" << p.id << std::endl;
}
 
int Foo::counter = 0;

int main(int argc, char *argv[]){
    //Foo p0;
    std::unique_ptr<Foo> p1(new Foo);  // p1 es propietario de la estructura Foo
    if(p1) {// Verificamos que exista p1, este codigo es lo mismo que poner p1!=NULL
        p1->bar();
    }   
    std::unique_ptr<Foo> p2(std::move(p1));  // ahora p2 es propietario de Foo
    f(*p2);
    p1 = std::move(p2);  // Regresamos el ownership a p1
    std::cout << "Destruyendo p2 por que nadie mas lo usa" << std::endl;
    std::shared_ptr<Foo> p3(std::move(p1));
    //delete &p0; // No liberen memoria estatica!!!
    delete p3;
    if(p1){ 
        p1->bar();
    }else{
        std::cout << "p1 ya no existe" << std::endl;
    }
 
    // La instancia de Foo es destruida cuando P1 va fuera del scope
}

/**
 * @brief Salida
 * Output:
 *
 *    Foo::Foo
 *    Foo::bar
 *    f(const Foo&)
 *    destroying p2...
 *    Foo::bar
 *    Foo::~Foo 
 */