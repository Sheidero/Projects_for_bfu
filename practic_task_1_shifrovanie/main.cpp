#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>

class FibonacciShifr{
private:
    std::vector<int> m_fibonacciSequence;
    std::vector<int> m_key;

    bool isFibonacciSequence(std::vector<int> new_key){
        int size = new_key.size();
        std::sort(new_key.begin(), new_key.end());
        for (int i = 0; i < size; i++) {
            if (m_fibonacciSequence[i] != new_key[i])
                return false;
        }
        return true;
    }

    std::vector<std::string> split(std::string text){
        std::vector<std::string> words;
        std::stringstream a(text);
        std::string word;
        while (a >> word) {
            words.push_back(word);
        }
        return words;
    }
    
    int getFibonacciNumber(int n){
        return (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
    }
public:
    FibonacciShifr(){
        for(int i = 2; i < 32; i++){
            m_fibonacciSequence.push_back(getFibonacciNumber(i));
        }
    }

    void setKey(std::vector<int> new_key){
        if(new_key.size() <= 30 && isFibonacciSequence(new_key)){
            m_key = new_key;
        }
        else{
            throw std::logic_error("The key size must be < 30, also be a Fibonacci sequence");
        }
    }
    std::vector<int> GetKey(){
        return m_key;
        }

    std::string Encode(std::string sentence) {
        std::vector<std::string> words = split(sentence);
        if (words.size() != m_key.size()) {
            throw std::logic_error("Key size must be equals amount of words");
        }
        std::stringstream sentence_encode;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (m_key[i] == m_fibonacciSequence[j]) {
                    if (i != 0) {
                        sentence_encode << ' ';
                    }
                    sentence_encode << words[j];
                    break;
                }
            }
        }
        return sentence_encode.str();
    }


    std::string Decode(std::string sentence){
        std::vector<std::string> words = split(sentence);
        if (words.size() != m_key.size()) {
            throw std::logic_error("Key size must be equals amount of words");
        }
        std::stringstream sentence_decode;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (m_key[j] == m_fibonacciSequence[i]) {
                    if (i != 0) {
                        sentence_decode << ' ';
                    }
                    sentence_decode << words[j];
                    break;
                }
            }
        }
        sentence_decode << std::endl;
        return sentence_decode.str();
    }

};
int main() {
    FibonacciShifr fibonacci;
    std::string text = "Hello, my name is Artem.";
    try {
        fibonacci.setKey({1, 3, 5, 8, 2});
        std::string encoded = fibonacci.Encode(text);
        std::cout << encoded << std::endl;
        std::cout << fibonacci.Decode(encoded);
    }
    catch(std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
