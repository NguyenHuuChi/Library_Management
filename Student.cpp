#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<vector>
#include<list>
#include"Library.h"
using namespace std;

class Student{
    private:
        string name;
        int age;
        string ID;
        vector<Book> borrowed_book;
    public:
        Student(string name , int age, string ID){
            this->name=name;
            this-> age=age;
            this->ID =ID;
        }
        void Borrow_book(Library & library,Book & book){
            borrowed_book.push_back(book);
            // check_index index =hash_function(book.getTitle(), book.getAuthor(), book.getGenre());
            book->Borrow_book();
            
        }
        
};