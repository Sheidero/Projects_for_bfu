#include <iostream>

int main(){
    const int N = 1000;
    int mas_a[N] = {1,2,3,4,5};
    int mas_b[N] = {0};
    int* temp_a = mas_a;
    int* temp_b = mas_b;
    for (int i = 0; i < sizeof(mas_a)/sizeof(mas_a[0]); i++){
         *temp_a = *(temp_b + i);
         temp_a += 1;
    }
    std::cout << mas_a << std::endl;
    std::cout << *mas_a << std::endl;
    std::cout << mas_b << std::endl;
    std::cout << *mas_b << std::endl;
    return 0;
}