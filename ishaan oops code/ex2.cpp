#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    int number;

protected:
    string brand;

public:
    void setVehicle() {
        number = 101;
        brand = "Audi";
    }

    void displayVehicle() {
        cout << "Vehicle Number: " << number << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Vehicle {
private:
    string model;

public:
    void setCar() {
        model = "SUV";
    }

    void displayCar() {
        displayVehicle();
        cout << "Model: " << model << endl;
    }
};

int main() {
    Car c;

    c.setVehicle();
    c.setCar();
    c.displayCar();

    return 0;
}