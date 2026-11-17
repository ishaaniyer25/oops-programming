#include <iostream>
using namespace std;

class Number {
private:
    int* value;

public:
    // 1. Default Constructor
    Number() {
        value = new int(0);
        cout << "Default Constructor" << endl;
    }

    // 2. Parameterized Constructor
    Number(int x) {
        value = new int(x);
        cout << "Parameterized Constructor" << endl;
    }

    // 3. Copy Constructor
    Number(const Number& n) {
        value = new int(*n.value);
        cout << "Copy Constructor" << endl;
    }

    // 4. Move Constructor
    Number(Number&& n) {
        value = n.value;
        n.value = nullptr;
        cout << "Move Constructor" << endl;
    }

    // 5. Copy Assignment Operator
    Number& operator=(const Number& n) {
        if (this != &n) {
            if (value == nullptr)
                value = new int(*n.value);
            else
                *value = *n.value;
        }

        cout << "Copy Assignment" << endl;
        return *this;
    }

    // 6. Move Assignment Operator
    Number& operator=(Number&& n) {
        if (this != &n) {
            delete value;
            value = n.value;
            n.value = nullptr;
        }

        cout << "Move Assignment" << endl;
        return *this;
    }

    // 7. Destructor
    ~Number() {
        delete value;
        cout << "Destructor" << endl;
    }

    // Display Function
    void display() {
        if (value != nullptr) {
            cout << "Value: " << *value << endl;
        }
        else {
            cout << "Value: Empty" << endl;
        }
    }
};

int main() {
    Number n1;

    Number n2(10);

    Number n3 = n2;

    Number n4 = Number(20);

    n3 = n2;

    n4 = Number(30);

    n1.display();
    n2.display();
    n3.display();
    n4.display();

    return 0;
}