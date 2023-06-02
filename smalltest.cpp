#include <iostream>
#include <fstream>
using namespace std;
void History_borrow_and_return_book(const string a) {
    ofstream file("History.out", ios::app); // Open the file in append mode

    if (file.is_open()) {
        file << a << endl; // Write the string to the file
        file.close(); // Close the file
        cout << "String written to file successfully." << endl;
    } else {
        cout << "Failed to open the file." << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    History_borrow_and_return_book(input);

    return 0;
}