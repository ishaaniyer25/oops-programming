#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    double r;

    Circle(double radius) {
        r = radius;
    }

    double area() override {
        return 3.14 * r * r;
    }
};

class Rectangle : public Shape {
public:
    double l, b;

    Rectangle(double length, double breadth) {
        l = length;
        b = breadth;
    }

    double area() override {
        return l * b;
    }
};

class Triangle : public Shape {
public:
    double b, h;

    Triangle(double base, double height) {
        b = base;
        h = height;
    }

    double area() override {
        return 0.5 * b * h;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 8);

    Shape* s;

    s = &c;
    cout << "Circle Area: " << s->area() << endl;

    s = &r;
    cout << "Rectangle Area: " << s->area() << endl;

    s = &t;
    cout << "Triangle Area: " << s->area() << endl;

    return 0;
}