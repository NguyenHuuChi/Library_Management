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

#include "Library.h"
#include <iostream>

string capitalizeAllString(const string& str) {
    string result = str;

    // Capitalize each character
    for (char& c : result) {
        c = toupper(c);
    }

    return result;
}

Book::Book(string title, string author, string genre) {
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->available= true;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getGenre() const {
    return genre;
}

bool Book::operator==(const Book& other) const {
    return (title == other.getTitle() && author == other.getAuthor());
}

bool Book::operator<(const Book& other) const {
    if (title == other.getTitle()) {
        return author < other.getAuthor();
    }
    return (title < other.getTitle());
}

bool Book::getAvailable() {
    return available;
}

void Book::Borrow_book() {
    this->available = 0;
}

void Book::Return_book() {
    this->available = 1;
}

void Book::get_information() {
    cout << "The title: " << title << " . The author : " << author << " . The genre : " << genre  << endl;
}


// This part is for split the information from file input purpose only
struct information_book{
    string title;
    string author;
    string genre;
};
//This function used to solve the space character in first and final of a string
string trimSentence(string sentence) {
    size_t start = sentence.find_first_not_of(" ");
    size_t end = sentence.find_last_not_of(" ");

    if (start == std::string::npos) {
        // No non-space characters found, return an empty string
        return "";
    }

    return sentence.substr(start, end - start + 1);
};
information_book read_line(string line){
    string delimiter1="*Title:";
    string delimiter2= "*Author:";
    string delimiter3="*Genre:";
    information_book book;
    string genre;
    string title;
    string author;
    size_t start = 0;
    size_t end1 = line.find(delimiter1); // Find the position of the word delimiter
    size_t end2 = line.find(delimiter2);
    size_t end3= line.find(delimiter3);
    title =line.substr(end1 + delimiter1.length(), end2 -delimiter2.length() );
    author= line.substr(end2 + delimiter2.length(),end3 -end2-delimiter2.length());
    genre=line.substr(end3 +delimiter3.length(), line.length() );    
    title=capitalizeAllString(title);
    author=capitalizeAllString(author);
    genre=capitalizeAllString(genre);  
    book.title=trimSentence(title);
    book.author=trimSentence(author);
    book.genre=trimSentence(genre);
    return book;
}


check_index hash_function(string title, string author, string genre) {
    check_index result;
    title = trimSentence(title);
    author = trimSentence(author);
    genre = trimSentence(genre);

    int check_author1 = author[0];
    int check_author2 = author[author.length() / 2];
    int check_title1 = title[0];
    int check_title2 = title[title.length() / 2];
    int check_genre1 = genre[0];
    int check_genre2 = genre[genre.length() / 2];

    if (isupper(check_author1))
        check_author1 += 'a' - 'A';
    if (isupper(check_author2))
        check_author2 += 'a' - 'A';
    if (isupper(check_title1))
        check_title1 += 'a' - 'A';
    if (isupper(check_title2))
        check_title2 += 'a' - 'A';
    if (isupper(check_genre1))
        check_genre1 += 'a' - 'A';
    if (isupper(check_genre2))
        check_genre2 += 'a' - 'A';

    int check_author = check_author1 + check_author2;
    if (check_author >200)check_author-=200;
    if (check_author >100)check_author-=100;
    if (check_author>50) check_author-=50;
    int check_title = check_title1 + check_title2;
    if (check_title >200)check_title-=200;
    if (check_title>100)check_title-=100;
    if (check_title>50) check_title-=50;
    int check_genre = check_genre1 + check_genre2;
    if (check_genre>200)check_genre-=200;
    if (check_genre >100) check_genre-=100;
    if (check_genre>50) check_genre-=50;
    if (check_genre> 25) check_genre-=25;

    result.check_title = check_title;
    result.check_author = check_author;
    result.check_genre = check_genre;

    return result;
};


void Library::locate_the_book(Book book) {
    string title = book.getTitle();
    string author = book.getAuthor();
    string genre = book.getGenre();
    check_index locate_book = hash_function(title, author, genre);
    ALL_BOOK[locate_book.check_genre][locate_book.check_title][locate_book.check_author].push_back(book);
    Book book1 = ALL_BOOK[locate_book.check_genre][locate_book.check_title][locate_book.check_author][0];
}

Library::Library() {
    ALL_BOOK = vector<vector<vector<vector<Book>>>>(26, vector<vector<vector<Book>>>(51, vector<vector<Book>>(51, vector<Book>(0))));
    string title_name;
    string author_name;
    ifstream Data_base_book("book.inp");
    if (Data_base_book.is_open()) {
        string line;
        while (getline(Data_base_book, line)) {
            information_book book = read_line(line);
            Book book1(book.title, book.author, book.genre);
            locate_the_book(book1);
        }
        Data_base_book.close();
    }
    else {
        cerr << "Failed to open the file book.inp." << endl;
    }
}

vector<vector<vector<vector<Book>>>> Library :: get_ALLBOOK(){
    return ALL_BOOK;
}

void Library :: Borrow_in_lib(Book book){
    string title=trimSentence(book.getTitle());
    string author=trimSentence(book.getAuthor());
    string genre=trimSentence(book.getGenre());
    check_index index=hash_function(title,author,genre);
    int check_title= index.check_title;
    int check_author=index.check_author;
    int check_genre=index.check_genre;
    for(int i=0; i< ALL_BOOK[check_genre][check_title][check_author].size(); i++){
        Book books=ALL_BOOK[check_genre][check_title][check_author][i];
        if(books.getTitle()== title && books.getAuthor()==author && books.getGenre()==genre){        
            ALL_BOOK[check_genre][check_title][check_author][i].Borrow_book();
        } 
    };
}

void Library :: Return_in_lib(Book book){
    string title=trimSentence(book.getTitle());
    string author=trimSentence(book.getAuthor());
    string genre=trimSentence(book.getGenre());
    check_index index=hash_function(title,author,genre);
    int check_title= index.check_title;
    int check_author=index.check_author;
    int check_genre=index.check_genre;
    for(int i=0; i< ALL_BOOK[check_genre][check_title][check_author].size(); i++){
        Book books=ALL_BOOK[check_genre][check_title][check_author][i];
        if(books.getTitle()== title && books.getAuthor()==author && books.getGenre()==genre){      
            ALL_BOOK[check_genre][check_title][check_author][i].Return_book();
        } 
    };
}
/* this function will return the index location of the book
return the location if it is available otherwise return the final index =-1*/
index_of_location Library::Find_the_book_availabel(string title, string author, string genre) {
    index_of_location location;
    title = trimSentence(title);
    author = trimSentence(author);
    genre = trimSentence(genre);
    title=capitalizeAllString(title);
    author=capitalizeAllString(author);
    genre=capitalizeAllString(genre); 
    Book book_find(title, author, genre);
    check_index index = hash_function(title, author, genre);
    int check_title = index.check_title;
    int check_author = index.check_author;
    int check_genre = index.check_genre;
    location.author=check_author;
    location.genre=check_genre;
    location.title=check_title;
    for (int i=0; i< ALL_BOOK[check_genre][check_title][check_author].size(); i++) {
        
        if (ALL_BOOK[check_genre][check_title][check_author][i] == book_find) {
            if (ALL_BOOK[check_genre][check_title][check_author][i].getAvailable()) {
                cout << "The book: " << title << " by " << author << " is available!" << endl;
                location.index=i;
                return location;
            }
        }
    }
    cout << "The book: " << title << " by " << author << " is not available!" << endl;
    location.index=-1;
    return location;
}

vector<Book> Library::Find_book_with_special_info(string title, string author, string genre) {
    title=trimSentence(title);
    author=trimSentence(author);
    genre=trimSentence(genre);
    title=capitalizeAllString(title);
    author=capitalizeAllString(author);
    genre=capitalizeAllString(genre); 
    check_index index = hash_function(title, author, genre);
    int check_title = index.check_title;
    int check_author = index.check_author;
    int check_genre = index.check_genre;
    string up_title = title;
    up_title[0] = toupper(up_title[0]);
    string up_author = author;
    up_author[0] = toupper(up_author[0]);
    string up_genre = genre;
    up_genre[0] = toupper(up_genre[0]);
    vector<Book> related_title;
    vector<Book> related_author;
    vector<Book> related_genre;

    if (title == "-1") {
        if (genre == "-1") {
            for (int i = 0; i < ALL_BOOK.size(); i++) {
                for (int j = 0; j < ALL_BOOK[i].size(); j++) {
                    if (check_author < ALL_BOOK[i][j].size()) {
                        for (Book book : ALL_BOOK[i][j][check_author]) {
                            if (book.getAuthor() == author || book.getAuthor() == up_author) {
                                related_author.push_back(book);
                            }
                        }
                    }
                }
            }
        }
        else if (author == "-1") {
            if (check_genre < ALL_BOOK.size()) {
                for (int i = 0; i < ALL_BOOK[check_genre].size(); i++) {
                    for (int j = 0; j < ALL_BOOK[check_genre][i].size(); j++) {
                        for (Book book : ALL_BOOK[check_genre][i][j]) {
                            if (book.getGenre() == genre || book.getGenre() == up_genre) {
                                related_genre.push_back(book);
                            }
                        }
                    }
                }
            }
        }
        else {
            if (check_genre < ALL_BOOK.size()) {
                for (int i = 0; i < ALL_BOOK[check_genre].size(); i++) {
                    if (check_author < ALL_BOOK[check_genre][i].size()) {
                        for (Book book : ALL_BOOK[check_genre][i][check_author]) {
                            if ((book.getAuthor() == author || book.getAuthor() == up_author) &&
                                (book.getGenre() == genre || book.getGenre() == up_genre)) {
                                related_author.push_back(book);
                            }
                        }
                    }
                }
            }
        }
    }

    if (author == "-1" && title != "-1") {
        if (genre == "-1") {
            for (int i = 0; i < ALL_BOOK.size(); i++) {
                if (check_title < ALL_BOOK[i].size()) {
                    for (int j = 0; j < ALL_BOOK[i][check_title].size(); j++) {
                        for (Book book : ALL_BOOK[i][check_title][j]) {
                            if (book.getTitle() == title || book.getTitle() == up_title) {
                                related_title.push_back(book);
                            }
                        }
                    }
                }
            }
        }
        else {
            if (check_genre < ALL_BOOK.size() && check_title < ALL_BOOK[check_genre].size()) {
                for (int i = 0; i < ALL_BOOK[check_genre][check_title].size(); i++) {
                    for (Book book : ALL_BOOK[check_genre][check_title][i]) {
                        if ((book.getTitle() == title || book.getTitle() == up_title) &&
                            (book.getGenre() == genre || book.getGenre() == up_genre)) {
                            related_title.push_back(book);
                        }
                    }
                }
            }
        }
    }
    if(author!="-1" && title !="-1" && genre =="-1"){
        for(int i=0; i< ALL_BOOK.size(); i++){
            if( check_title <ALL_BOOK[i].size() && check_author <ALL_BOOK[i][check_title].size()){
                for( Book book :ALL_BOOK[i][check_title][check_author]){
                    if ((book.getTitle() == title || book.getTitle() == up_title) &&
                        (book.getAuthor() == author || book.getAuthor() == up_author)) {
                        related_title.push_back(book);
                    }
                }   
            }
        }
    }
    int i=0;
    if (!related_title.empty()) {
        cout << "List of books whose title is " <<"\"" << title << "\":\n";
        for (Book book : related_title) {
            cout <<  i <<" : ";
            book.get_information();
            i++;
        }
        return related_title;
    }
    else if (!related_author.empty()) {
        cout << "List of books whose author is " <<"\""<< author << "\":\n";
        for (Book book : related_author) {
            cout <<  i <<" : ";
            book.get_information();
            i++;
        }
        return related_author;
    }
    else if (!related_genre.empty()) {
        cout << "List of books whose genre is "<<"\"" << genre << "\":\n";
        for (Book book : related_genre) {
            cout <<  i <<" : ";
            book.get_information();
            i++;
        }
        return related_genre;
    }
    else {
        cout << "Cannot find any book." << endl;
        return related_author;
    }
}
