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


struct check_index{
    int check_title;
    int check_author;
    int check_genre;
};
typedef check_index check_index;
check_index hash_function(string title, string author, string genre);
class Book{
    private :
        string title;
        string author;
        string genre;
        bool available;
    public:
        Book(string title = "", string author = "", string genre = "");
        string getTitle() const ;
        string getAuthor() const ;
        string getGenre() const ;
        bool operator==(const Book & other)const;
        bool operator<(const Book & other ) const;
        bool getAvailable();
        void Borrow_book();
        void Return_book();
        void get_information();
};


class Library{
    private : 
        vector<vector<vector<vector<Book>>>> ALL_BOOK;
        void locate_the_book(Book book);
    public:
        Library();
        bool Find_the_book_availabel(string title,string author,string genre );
        vector<Book> Find_book_with_special_info(string title="-1", string author="-1", string genre="-1");
};