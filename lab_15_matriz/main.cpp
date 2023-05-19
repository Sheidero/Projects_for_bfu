#include <iostream>
#include "matrix.hpp"

int main(){
    Matriz<int,2,2> m;
    Matriz<int,2,2> k(m);
    Matriz<int,2,2> s;
    s = k + m;
    s += k;
    s *= k;
    Matriz<int,2,2> a;
    std::cout << a * a;
    std::cout << ++a;
    std::cout << s;
    std::cin >> m;
    std::cout << m;
    std::cout << m.determinant() << std::endl;
    std::cout << m.Get(1,0);
    m.Set(1,0,10);
    std::cout << m.Get(1,0);
}