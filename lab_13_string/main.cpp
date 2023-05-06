#include <iostream>


 class String
 {
 private:
 	size_t m_size;
 	char* m_str;
 	mutable int m_counter = 0;
 public:
 	String(char* str)
 	{
 		m_size = strlen(str); // '\0'
 		m_str = new char[m_size+1];
 		std::copy(str, str+m_size+1, m_str); // memcpy
 	}

 	explicit String(char c, size_t size)  // Неявное преобразование типов из int в char
 	{
 		m_size = size;
 		m_str = new char[size];
 		for (int i = 0; i < m_size; i++)
 			m_str[i] = c;
 	}

 	size_t Size() const		// Константный метод
 	{
 		return m_size;
 	}

 	void Print() const
 	{
 		m_counter++;
 		std::cout << m_counter << std::endl;
 		std::cout << m_str << std::endl;
 	}
 };

int main() {
    std::cout << "Hello, World" << std::endl;
    return 0;
}