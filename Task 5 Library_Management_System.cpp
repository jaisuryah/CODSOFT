#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
};

// Library Management System class
class Library {
private:
    vector<Book> books;

public:
    // Function to add a book to the library
    void addBook(const string& title, const string& author, const string& ISBN) {
        books.push_back({title, author, ISBN, true});
    }

    // Function to search for a book by title, author, or ISBN
    void searchBook(const string& query) {
        for (const Book& book : books) {
            if (book.title == query || book.author == query || book.ISBN == query) {
                cout << "Book found: " << book.title << " by " << book.author << " (ISBN: " << book.ISBN << ")" << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // Function to check out a book
    void checkOutBook(const string& ISBN) {
        for (Book& book : books) {
            if (book.ISBN == ISBN) {
                if (book.available) {
                    book.available = false;
                    cout << "Book checked out successfully." << endl;
                } else {
                    cout << "Book is not available." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // Function to return a book
    void returnBook(const string& ISBN) {
        for (Book& book : books) {
            if (book.ISBN == ISBN) {
                book.available = true;
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    Library library;

    // Adding sample books to the library
    library.addBook("Book1", "Author1", "ISBN001");
    library.addBook("Book2", "Author2", "ISBN002");
    library.addBook("Book3", "Author3", "ISBN003");

    // User interface (simplified command-line interface)
    int choice;
    string input;
    do {
        cout << "Library Management System\n";
        cout << "1. Search book\n2. Check out book\n3. Return book\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title, author, or ISBN to search: ";
                cin.ignore(); // Ignore newline in buffer
                getline(cin, input);
                library.searchBook(input);
                break;
            case 2:
                cout << "Enter book ISBN to check out: ";
                cin >> input;
                library.checkOutBook(input);
                break;
            case 3:
                cout << "Enter book ISBN to return: ";
                cin >> input;
                library.returnBook(input);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
