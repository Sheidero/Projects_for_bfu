#include <iostream>

class Shifr
{
private:
    char* m_text;
public:
    Shifr(const char* s){
        
    }
    ~Shifr(){
        delete[] m_text;
    }
};

int main(){

}