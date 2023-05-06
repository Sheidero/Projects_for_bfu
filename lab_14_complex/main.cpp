#include <iostream>

class Complex {
private:
    double m_a;
    double m_b;
public:
    explicit Complex(double a = 0.0, double b = 0.0) {
        std::cout << "Basic constructor" << std::endl;
        m_a = a;
        m_b = b;
    }
    Complex(const Complex &temp){
        std::cout << "Copy constructor" << std::endl;
        m_a = temp.m_a;
        m_b = temp.m_b;
    }
    ~Complex() = default;
    const Complex& operator=(const Complex &temp){
        std::cout << "Copy assigment operator" << std::endl;
        m_a = temp.m_a;
        m_b = temp.m_b;
        return *this;
    }
    const Complex& operator+(const Complex &temp) {
        m_a += temp.m_a;
        m_b += temp.m_b;
        return *this;
    }
    const Complex& operator-(const Complex &temp) {
        m_a -= temp.m_a;
        m_b -= temp.m_b;
        return *this;
    }
    const Complex& operator+=(const Complex &temp) {
        m_a += temp.m_a;
        m_b += temp.m_b;
        return *this;
    }
    const Complex& operator*=(const Complex &temp) {
        m_a = m_a * temp.m_a - m_b * temp.m_b;
        m_b = m_a * temp.m_b + m_b * temp.m_a;
        return *this;
    }
    const Complex& operator*(const Complex &temp) {
        m_a = m_a * temp.m_a - m_b * temp.m_b;
        m_b = m_a * temp.m_b + m_b * temp.m_a;
        return *this;
    }
    Complex operator++() {
        std::cout<<"prefix operator" << std::endl;
        m_a += 1;
        return *this;
    }

    Complex operator++(int) {
        std::cout<< "postfix operator" << std::endl;
        Complex copy = *this;
        m_a += 1;
        return copy;
    }
    // Так писать не нужно
    /*
    void See() const {
        if (m_b != 0)
        std::cout<< m_a << " + " << m_b << "i" << std::endl;
        else
        std::cout<< m_a << std::endl;
    }
    void Insert() {
        std::cout<<"Enter real part ";
        std::cin >> m_a;
        std::cout<< "\n" << "Enter image part ";
        std::cin >> m_b;
        std::cout<< "\n";
    }
    */
    // использование приватной переменной во внешней функции
    friend std::ostream& operator<<(std::ostream& out,const Complex& temp);
    friend std::istream& operator>>(std::istream& in, Complex& temp);
};
// переопределение операторов вывода и ввода для класса Complex
std::ostream& operator<<(std::ostream& out,const Complex& temp){
    out << temp.m_a << " + " << temp.m_b << "i" <<std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, Complex& temp){
    in >> temp.m_a >> temp.m_b;
    return in;
}

int main() {
    Complex a(1,2);
    Complex b(2,1);
    std::cout << a;
    std::cout << b;
    std::cout << a * b;
    std::cin >> a;
    std::cout << a++;
    return 0;
}