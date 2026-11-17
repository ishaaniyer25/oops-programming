#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// Base Class
class Book {
protected:
    int id;
    string name;
    string author;
    bool issued;

public:
    Book(int i, string n, string a) {
        id = i;
        name = n;
        author = a;
        issued = false;
    }

    virtual void display() {
        cout << id << "  " << name << "  "
             << author << "  "
             << (issued ? "Issued" : "Available")
             << endl;
    }

    int getId() {
        return id;
    }

    bool isIssued() {
        return issued;
    }

    void issue() {
        if (issued)
            throw "Book is already issued!";

        issued = true;
    }

    void returnBook() {
        if (!issued)
            throw "Book was not issued!";

        issued = false;
    }

    virtual ~Book() {}
};

// Derived Class
class Library : public Book {
private:
    vector<Book> books;

public:
    Library() : Book(0, "", "") {}

    void addBook(int id, string name, string author) {
        books.push_back(Book(id, name, author));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        cout << "\nID  Name  Author  Status\n";

        for (auto &b : books) {
            b.display();
        }
    }

    void searchBook(int id) {
        auto it = find_if(books.begin(), books.end(),
            [id](Book &b) {
                return b.getId() == id;
            });

        if (it != books.end())
            it->display();
        else
            cout << "Book not found!\n";
    }

    void issueBook(int id) {
        for (auto &b : books) {
            if (b.getId() == id) {
                b.issue();
                cout << "Book issued successfully!\n";
                return;
            }
        }

        cout << "Book not found!\n";
    }

    void returnBook(int id) {
        for (auto &b : books) {
            if (b.getId() == id) {
                b.returnBook();
                cout << "Book returned successfully!\n";
                return;
            }
        }

        cout << "Book not found!\n";
    }

    void saveToFile() {
        ofstream file("library.txt");

        for (auto &b : books) {
            // Save basic book details
            // Status is saved as 0 or 1
            file << b.getId() << ","
                 << (b.isIssued() ? 1 : 0) << endl;
        }

        file.close();
        cout << "Data saved to file!\n";
    }
};

// Main Function
int main() {

    Library lib;
    int choice, id;
    string name, author;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Save Data\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {

            case 1:
                cout << "Enter Book ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Book Name: ";
                getline(cin, name);

                cout << "Enter Author Name: ";
                getline(cin, author);

                lib.addBook(id, name, author);
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.searchBook(id);
                break;

            case 4:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.issueBook(id);
                break;

            case 5:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 6:
                lib.saveToFile();
                break;

            case 7:
                cout << "Thank you for using Library System!\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }
        }
        catch (const char* error) {
            cout << "Error: " << error << endl;
        }

    } while (choice != 7);

    return 0;
}