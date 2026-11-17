#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
private:
    T arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(T value) {
        if (top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Popped: " << arr[top--] << endl;
    }

    void display() {
        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.display();
    s1.pop();

    Stack<float> s2;

    s2.push(1.5f);
    s2.push(2.5f);

    s2.display();

    Stack<string> s3;

    s3.push("Hello");
    s3.push("ADYPU");

    s3.display();

    return 0;
}