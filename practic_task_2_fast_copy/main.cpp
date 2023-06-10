#include <iostream>

template<typename T>
void fast_copy(const int N,T* mas_a,T* mas_b){
    const long long* tag_a1 = (const long long*)mas_a;
    long long* tag_b1 = (long long*)mas_b;
	int m = sizeof(T) * N / sizeof(long long);

	for (int i = 0; i < m; ++i){
		*(tag_b1++) = *(tag_a1++);
	}

	char* tag_a2 = (char*)tag_a1;
	char* tag_b2 = (char*)tag_b1;
	m = (sizeof(T) * N) % sizeof(long long);
    
	for (int i = 0; i < m; i++){
		*(tag_b2++) = *(tag_a2++);
	}
}

int main(){
    const int N = 1000;
    int mas_a[N] = {1,2,3,4,5};
    int mas_b[N] = {0};
    fast_copy<int>(N,mas_a,mas_b);
    std::cout << mas_a << std::endl;
    std::cout << *mas_a << std::endl;
    std::cout << mas_b << std::endl;
    std::cout << *mas_b << std::endl;
    return 0;
}