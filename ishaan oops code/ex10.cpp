#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    // Creating and opening CSV file
    fstream file("students.csv",
                 ios::in | ios::out | ios::trunc);

    if (!file) {
        cout << "File opening failed!";
        return 1;
    }

    // Writing student records
    file << "RollNo,Name,Marks\n";
    file << "101,Amaan,85\n";
    file << "102,Sara,92\n";

    file.flush();

    cout << "Student records written successfully.\n";

    // Using tellp()
    cout << "Write pointer position: "
         << file.tellp() << endl;

    // Using seekp()
    file.seekp(0, ios::end);

    // Adding another record
    file << "103,Rahul,78\n";
    file.flush();

    cout << "New record added successfully.\n";

    cout << "Write pointer position after adding: "
         << file.tellp() << endl;

    // Using seekg()
    file.seekg(0, ios::beg);

    cout << "\nReading Student Records:\n";

    // Using tellg()
    cout << "Read pointer position: "
         << file.tellg() << endl;

    string line;

    // Reading header
    getline(file, line);

    cout << "Header: " << line << endl;

    cout << "Read pointer after header: "
         << file.tellg() << endl;

    // Reading student records
    while (getline(file, line)) {
        stringstream ss(line);

        string rollNo, name, marks;

        getline(ss, rollNo, ',');
        getline(ss, name, ',');
        getline(ss, marks, ',');

        cout << "Roll No: " << rollNo
             << ", Name: " << name
             << ", Marks: " << marks << endl;
    }

    file.close();

    return 0;
}