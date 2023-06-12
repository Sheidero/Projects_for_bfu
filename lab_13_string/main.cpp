#include <iostream>

class String {
private:
    char* m_text;
    int m_size;

    void fill(const char* text, int size) {
        m_text = new char[size];
        for (int i = 0; i < size; i++) {
            m_text[i] = text[i];
        }
    }

public:

    String(const char* text) {
        m_size = 0;
        while (text[m_size]) {
            m_size++;
        }

        fill(text, m_size);
    }

    String(const String& temp) {
        m_size = temp.m_size;
        fill(temp.m_text, m_size);
    }
	~String() {
        delete[] m_text;
    }
    String& operator = (const String& temp) {
		if (this == &temp) {
			return *this;
		}
        delete[] m_text;
        m_size = temp.m_size;
        fill(temp.m_text, m_size);
        return *this;
    }
    String operator + (const String& temp) {
		
        char* new_text = new char[m_size + temp.m_size];

        for (int i = 0; i < m_size; i++) {
            new_text[i] = m_text[i];
        }
        for (int i = 0; i < temp.m_size; i++) {
            new_text[m_size + i] = temp.m_text[i];
        }
        String new_string = String(new_text);
        delete[] new_text;
        return new_string;
    }

    String& operator += (const String& temp) {
        char* new_text = new char[m_size + temp.m_size];

        for (int i = 0; i < m_size; i++) {
            new_text[i] = m_text[i];
        }
        for (int i = 0; i < temp.m_size; i++) {
            new_text[m_size + i] = temp.m_text[i];
        }
		m_size += temp.m_size;
        delete[] m_text;
		fill(new_text,m_size);
		delete[] new_text;
        return *this;
    }

    char& operator [] (int index) {
        return m_text[index];
    }

    bool operator < (const String& temp) {
		if (m_size < temp.m_size){
			return 1;
		}
		if (m_size == temp.m_size){
			if (m_text[0] < temp.m_text[0]){
				return 1;
			}
		}
        return 0;
    }

    bool operator > (const String& temp) {
		if (m_size > temp.m_size){
			return 1;
		}
		if (m_size == temp.m_size){
			if (m_text[0] > temp.m_text[0]){
				return 1;
			}
		}
        return 0;
    }

    bool operator == (const String& temp) {
        return m_text == temp.m_text;
    }

    int find(char a) {
        for (int i = 0; i < m_size; i++) {
            if (m_text[i] == a) {
                return i;
            }
        }
        return -1;
    }

    int length() {
        return m_size;
    }

    char* str() {
        return m_text;
    }

    char at(int n, char a = -1) {
        if (0 <= n && n < m_size) {
			if (a != -1){
				m_text[n] = a;
			}
            return m_text[n];
        }
        return -1;
    }

    friend std::ostream& operator << (std::ostream& os, const String& temp);
    friend std::istream& operator >> (std::istream& in, String& s);
};

std::ostream& operator << (std::ostream& out, const String& temp) {
    out << temp.m_text;
    return out;
}

std::istream& operator >> (std::istream& in, String& temp) {
    in >> temp.m_text;
    int size = 0;
    while (temp.m_text[size]) {
        size++;
    }
    temp.m_size = size;
    return in;
}

int main()
{
	String a("good");
	String b("adfe");
	String k("perfect");
	std::cout<< a + a << " " << a.at(3,'k') << std::endl;
	
	std::cout<< a.length() << " " << a << std::endl;
	a[3] = 't';
	std::cout << a << std::endl;
	std::cout << (a < b) << " " << (a == b) << " " << (a > b) << std::endl;
	a += b;
	std::cout << a.length() << " " << a << std::endl;
	
	a = b;
	std::cout << a << " " << b << std::endl;
	String h(k);
	std::cout << k << " " << h << std::endl;
	std::cout << k.str() << " " << k.find('r') << " " << k.length() << std::endl;
	return 0;
}