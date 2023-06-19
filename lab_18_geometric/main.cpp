#include <iostream>
#include <string>
#include <math.h>

#define _USE_MATH_DEFINES

// Родительский класс Shape |v
class Shape {
private:
    double m_coordinates[2];
    std::string m_color;

public:
    Shape(const double coordinates[2], const std::string color) {
        m_coordinates[0] = coordinates[0];
        m_coordinates[1] = coordinates[1];
        m_color = color;
    }
    virtual double Area() const = 0;
    virtual std::string GetColor(){
        return m_color;
    }
    virtual ~Shape() {};
};

class Triangle : virtual public Shape {
private:
    double m_sides[3];

public:
    Triangle(double coord[2], std::string color, double sides[3]) : Shape(coord, color) {
        for (int i = 0; i < 3; i++) {
            m_sides[i] = sides[i];
        }
    }

    double Area() const override{
        double a = m_sides[0], b = m_sides[1], c = m_sides[2];
        // p - полупериметр
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Rectangle : public virtual Shape {
private:
    double m_sides[2];
public:
    Rectangle(double coordinates[2], std::string color, double sides[2]) : Shape(coordinates, color) {
        m_sides[0] = sides[0];
        m_sides[1] = sides[1];
    }

    double Area() const override{
        return m_sides[0] * m_sides[1];
    }
};

class Circle : public virtual Shape {
private:
    double m_radius;
public:
    Circle(double coordinates[2], std::string color, double radius) : Shape(coordinates, color) {
        m_radius = radius;
    }

    double Area() const override{
        return M_PI * pow(m_radius,2);
    }
};

int main() {
    double baseCoord[2] = {0, 0};

    double triangleSides[3] = {20, 20, 15};
    std::string triangleColor = "#FF7F50"; // Coral
    Triangle* triangle = new Triangle(baseCoord, triangleColor, triangleSides);
    std::cout << "Triangle's area = " << triangle->Area() << std::endl;

    double rectangleSides[2] = {4, 5};
    std::string rectangleColor = "#00FFFF"; // Aqua
    Rectangle* rectangle = new Rectangle(baseCoord, rectangleColor, rectangleSides);
    std::cout << "Rectangle's area = " << rectangle->Area() << std::endl;

    double circleRadius = 10;
    std::string circleColor = "#C0C0C0"; // Silver
    Circle* circle = new Circle(baseCoord, circleColor, circleRadius);
    std::cout << "Circle's area = " << circle->Area() << std::endl;
    std::cout << "Circle's color - " << circle->GetColor() << std::endl;;
}
