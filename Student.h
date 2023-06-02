#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<vector>
#include<list>
#include <ctime>
#include"Library.h"
using namespace std;

struct information_borrow_book{
    index_of_location Index;
    time_t time;
};
typedef struct information_borrow_book information_borrow_book;

int Calculate_penalty_money(int day, int hour);

class Student{
    private:
        string name;
        int age;
        string ID;
        vector<pair< information_borrow_book ,Book>> list_borrowed_book;
    public:
        // return the value of list_book_borrow
        vector<pair< information_borrow_book ,Book>> list_book_borrow();

        //Declare constructor
        Student(string name , int age, string ID);

        //function borrow the book
        void Borrow_book(Library & library,Book book);

        //function return the book;
        void Return_book(Library &  Library, Book book);

};
class Manage_student{
    private: 
        vector<Student> List_student_borrow_book;
    public :
        vector<Student> get_list_student_borrow_book(){
            return List_student_borrow_book;
        };
        // function find student who borrow the special book;
        void Find_student_borrow_book(Library & Library, Book book);

        // This function to take input from user;
        void Take_infor_student_book();

        void History_borrow_and_return_book();



};