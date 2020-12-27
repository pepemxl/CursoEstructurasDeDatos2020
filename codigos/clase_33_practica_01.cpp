#include <iostream>
#include <memory>
 
struct Foo{
    Foo(){ 
        std::cout << "Foo::Foo" << std::endl;  
    }
    ~Foo(){ 
        std::cout << "Foo::~Foo" << std::endl; 
    }
    void bar() { 
        std::cout << "Foo::bar" << std::endl;  
        }
};
 
void f(const Foo &){
    std::cout << "f(const Foo&)" << std::endl;
}
 
int main(int argc, char *argv[]){
    std::unique_ptr<Foo> p1(new Foo);  // p1 es propietario de la estructura Foo
    if(p1) {// Verificamos que exista p1, este codigo es lo mismo que poner p1!=NULL
        p1->bar();
    }
   // {//Abrir esta llave crea un scope
        std::unique_ptr<Foo> p2(std::move(p1));  // ahora p2 es propietario de Foo
        f(*p2);
 
        p1 = std::move(p2);  // Regresamos el ownership a p1
        std::cout << "Destruyendo  p2" << std::endl;
    //}
 
    if(p1){ 
        p1->bar();
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