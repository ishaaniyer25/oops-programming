#include <iostream>
using namespace std;

int main()
{
    int age;
    float marks;
    char grade;
    bool passed;

    const int totalMarks = 100;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your marks: ";
    cin >> marks;

    float percentage = (marks / totalMarks) * 100;

    cout << "Age = " << age << endl;
    cout << "Marks = " << marks << endl;
    cout << "Percentage = " << percentage << "%" << endl;

    if (percentage >= 40)
        passed = true;
    else
        passed = false;

    cout << "Passed = " << passed << endl;

    return 0;
}