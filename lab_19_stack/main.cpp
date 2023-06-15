#include <iostream>
#include <string>

template<class T>
class Stack {
private:
    unsigned int m_maxSize;
    unsigned int m_currentSize = 0;
    T* m_elements;

public:
    Stack(unsigned int size) {
        m_maxSize = size;
        try {
            m_elements = new T[size];
        }
        catch (const std::bad_alloc& e) {
            std::cout << "ERROR: not enough memory" << std::endl;
        }
    }

    ~Stack() {
        delete[] m_elements;
    }

    int size() {
        return m_currentSize;
    }
    bool empty() {
        return m_currentSize == 0;
    }
    void push(T new_element) {
        if (m_currentSize < m_maxSize) {
            m_elements[m_currentSize] = new_element;
            m_currentSize++;
        }
        else {
            throw std::overflow_error("ERROR: stack is full");
        }
        // Метод push, чтобы положить элемент в стек
    }
    T pop(const int& i) {
        if (i >= m_currentSize) {
            throw std::out_of_range("ERROR: out of range");
        }
        else {
            T element = m_elements[i];
            for (int j = i; j < m_maxSize; j++) {
                m_elements[j] = m_elements[j + 1];
            }
            m_currentSize--;
            return element;
        }
        // Метод pop, чтобы извлечь элемент из стека
    }
    T top() {
        if (m_currentSize == 0) {
            throw std::logic_error("ERROR: stack is empty");
        }
        else {
            return m_elements[m_currentSize - 1];
        }
        // Метод top, чтобы посмотреть верхний элемент стека, но не извлекать его.
    }
};


int main() {
    Stack<int> stack(20);
    try {
        for (int i = 0; i < 5; i++) {
            stack.push(i);
        }
        std::cout << "Last element = " << stack.top() << std::endl;
        std::cout << "i element = " << stack.pop(2) << std::endl;
    }
    catch(std::overflow_error& e){
        std::cout << e.what() << std::endl;
    }
    catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }
    catch(std::logic_error& e){
        std::cout << e.what() << std::endl;
    }
    catch(std::string& e){
        std::cout << e << std::endl;
    }
    std::cout << "Is stack empty? - " << stack.empty() << std::endl;
    std::cout << "What is size? - " << stack.size() << std::endl;
    return 0;
}