#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    void getPerson() {
        cout << "Enter name: ";
        cin >> name;
    }
};

class Student : public Person {
public:
    int rollNo;

    void getStudent() {
        cout << "Enter roll number: ";
        cin >> rollNo;
    }
};

class GraduateStudent : public Student {
public:
    string researchTopic;

    void getGraduate() {
        cout << "Enter research topic: ";
        cin >> researchTopic;
    }

    void display() {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << rollNo;
        cout << "\nResearch Topic: " << researchTopic << endl;
    }
};

int main() {
    GraduateStudent g;

    g.getPerson();
    g.getStudent();
    g.getGraduate();

    g.display();

    return 0;
}