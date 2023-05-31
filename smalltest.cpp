#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Book{
    private :
        string title;
        string author;
        string genre;
        bool available;
    public:
        Book(string title, string author,string genre){
            this-> title =title;
            this -> author =author;
            this -> genre =genre;
        }
        string getTitle() const {
            return title;
        }
        string getAuthor() const {
            return author;
        }
        string getGenre() const {
            return genre;
        };
        bool operator==(const Book & other)const{    // the "const make sure that there is no change in attributes "
            return (title==other.getTitle() && author== other.getAuthor());
        }
        bool operator<(const Book & other ) const{
            if(title == other.getTitle()){
                return author <other.getAuthor();
            }
            return (title <other.getTitle());
        }
        bool getAvailable(){
            return available;
        }
        void Borrow_book(){
            available =1;
        }
        void Return_book(){
            available=0;
        }
        void get_information(){
            cout << "The book :" << title << "belong to " << author << " is " << genre << "type book \n";
        }
};


int main() {
    vector<vector<vector<vector<Book>>>> ALL_BOOK;

    // Resize the dimensions of ALL_BOOK
    ALL_BOOK.resize(1);  // Resize the first dimension
    ALL_BOOK[0].resize(1);  // Resize the second dimension
    ALL_BOOK[0][0].resize(1);  // Resize the third dimension
    // ALL_BOOK[0][0][0].resize(1);  // Resize the fourth dimension

    Book book("To Kill a Mockingbird", "Harper Lee", "Fiction");
    ALL_BOOK[0][0][0].push_back(book);

    Book book1 = ALL_BOOK[0][0][0][1];
    book1.get_information();

    return 0;
}