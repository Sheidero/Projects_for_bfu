#pragma once
#include <iostream>

template <typename T, int strochki, int stolbci>
class Matriz
{
private:
    T matrix[strochki][stolbci];

public:
    Matriz(T part = 1)
    {
        for (int i = 0; i < strochki; i++)
            for (int j = 0; j < stolbci; j++)
                matrix[i][j] = part;
    }
    Matriz(const Matriz<T, strochki, stolbci> &temp)
    {
        for (int i = 0; i < strochki; i++)
            for (int j = 0; j < stolbci; j++)
                matrix[i][j] = temp.matrix[i][j];
    }
    Matriz &operator=(const Matriz &temp)
    {
        // Пример, как и зачем использовать this в методах
        if (this == &temp)
        {
            return *this;
        }
        for (int i = 0; i < strochki; i++)
            for (int j = 0; j < stolbci; j++)
                matrix[i][j] = temp.matrix[i][j];
        return *this;
    }
    Matriz &operator+=(const Matriz &temp)
    {
        for (int i = 0; i < strochki; i++)
            for (int j = 0; j < stolbci; j++)
                matrix[i][j] += temp.matrix[i][j];
        return *this;
    }
    Matriz &operator+(const Matriz &temp)
    {
        *this += temp;
        return *this;
    }
    // Префиксный оператор
    Matriz operator++()
    {
        for (int i = 0; i < strochki; i++)
            for (int j = 0; j < stolbci; j++)
                matrix[i][j] += 1;
        return *this;
    }
    // Постфиксный оператор
    Matriz operator++(int)
    {
        Matriz temp = *this;
        for (int i = 0; i < strochki; i++)
            for (int j = 0; j < stolbci; j++)
                matrix[i][j] += 1;
        return temp;
    }
    Matriz &operator*=(const Matriz &temp)
    {
        Matriz<T, strochki, stolbci> copia(*this);
        for (int i = 0; i < strochki; i++)
            for (int j = 0; j < stolbci; j++){
                T res = matrix[i][0] * temp.matrix[0][j];
                for (int k = 1; k < strochki; k++)
                    res += matrix[i][k] * temp.matrix[k][j];
                copia.matrix[i][j] = res;
            }
        return copia;
    }
    Matriz &operator*(const Matriz &temp)
    {
        *this *= temp;
        return *this;
    }
    /*
    void See()
    {
        for (int i = 0; i < strochki; i++)
        {
            for (int j = 0; j < stolbci; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    }*/
    T determinant(){
        T m_det;
        if (strochki == stolbci){
            switch (strochki){
                case 1:
                    m_det = matrix[0][0];
                    break;
                case 2:
                    m_det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
                    break;
                case 3:
                    m_det = matrix[0][0] * matrix[1][1] * matrix[2][2] + \
                    matrix[0][1] * matrix[1][2] * matrix[2][0] + \
                    matrix[1][0] * matrix[2][1] * matrix[0][2] - \
                    matrix[0][2] * matrix[1][1] * matrix[2][0] - \
                    matrix[0][1] * matrix[1][0] * matrix[2][2] - \
                    matrix[0][0] * matrix[1][2] * matrix[2][1];
                    break;
                default:
                    break;
            }  
        }
        return m_det;
    }
    void Set(const int &stro, const int &stolb, const T &smth){
        matrix[stro][stolb] = smth;
    }
    // Почему работало с типом Matriz?
    T Get(const int &stro, const int &stolb){
        return matrix[stro][stolb];
    }
    friend std::ostream &operator<<(std::ostream &out, const Matriz &temp){
        for (int i = 0; i < strochki; i++)
        {
            for (int j = 0; j < stolbci; j++)
                out << temp.matrix[i][j] << " ";
            out << std::endl;
        }
        return out;
    }
    friend std::istream &operator>>(std::istream &in, Matriz &temp) {
        for (int i = 0; i < strochki; i++)
        {
            for (int j = 0; j < stolbci; j++)
                in >> temp.matrix[i][j];
        }
        return in;
    }
};

// template <typename T, int strochki, int stolbci>
// std::ostream &operator<<(std::ostream &out, const Matriz<T, strochki, stolbci> &temp)


//template <typename T, int strochki, int stolbci>
