#include <iostream>

template<const int N>
class Shifr
{
private:
    std::string s_m[N];
public:
    Shifr(std::string s){
        std::string real_s;
        real_s = s[0];
        short int k = 0;
        for (int i = 1, i<N, i++){
            if (s[i] == ' '){
                s_m[k] = real_s;
                k++;
            }
        }
    }
    ~Shifr();
};

int main(){

}