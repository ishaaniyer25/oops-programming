#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    vector<int> marks = {75, 90, 45, 80, 63};

    map<string, vector<int>> students = {
        {"Aayan", {90, 82}},
        {"Vivek", {78, 85}},
        {"Prashant", {84, 95}},
        {"Emmanuel", {88, 91}}
    };

    unordered_map<int, vector<int>> studentData = {
        {1, {75, 82, 90}},
        {2, {45, 94, 83}},
        {3, {80, 65, 92}}
    };

    cout << "Student Names and Marks:" << endl;
    for (const auto& student : students) {
        cout << student.first << ": ";
        for (int mark : student.second) {
            cout << mark << " ";
        }
        cout << endl;
    }

    cout << "\nSorted Marks:" << endl;
    sort(marks.begin(), marks.end());
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;

    auto it = find_if(marks.begin(), marks.end(),
                      [](int mark) { return mark > 80; });

    if (it != marks.end()) {
        cout << "First mark greater than 80: " << *it << endl;
    } else {
        cout << "No mark greater than 80." << endl;
    }

    vector<int> bonusMarks(marks.size());
    transform(marks.begin(), marks.end(), bonusMarks.begin(),
              [](int mark) { return mark + 5; });

    cout << "Bonus Marks:" << endl;
    for (int mark : bonusMarks) {
        cout << mark << " ";
    }
    cout << endl;

    cout << "\nStudent Roll No and Marks:" << endl;
    for (const auto& student : studentData) {
        cout << student.first << ": ";
        for (int mark : student.second) {
            cout << mark << " ";
        }
        cout << endl;
    }

    return 0;
}