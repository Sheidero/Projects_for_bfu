#include <iostream>
#include "matrix.hpp"

int main(){
    Matriz<int,2,3> m;
    Matriz<int,2,2> k;
    //Matriz<int,2,2> s(k+m);
    //std::cout<<"cool\n";
    std::cout << m;
    std::cin >> m;
    std::cout << m;
    std::cout << m.determinant() << std::endl;
}