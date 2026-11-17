#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;

    virtual ~Shape() {
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, breadth;

public:
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() override {
        return length * breadth;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() override {
        return 0.5 * base * height;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(8, 5);

    Shape* shapes[3];
    shapes[0] = &c;
    shapes[1] = &r;
    shapes[2] = &t;

    cout << "Circle Area: " << shapes[0]->area() << endl;
    cout << "Rectangle Area: " << shapes[1]->area() << endl;
    cout << "Triangle Area: " << shapes[2]->area() << endl;

    return 0;
}
