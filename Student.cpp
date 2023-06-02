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

// function to calculate the amount that 
int Calculate_penalty_money(int day, int hour){
    if (day <=2){
        cout << "Do not overdue the day of return of books";
        return 0;
    } else{
        cout << "Overdue the day of return of book !\n";
        cout << "Penalty_money :\n";
        int money=30000*(day-3) + hour*1000;
        cout << money;
        return money;
    }
};

class Student{
    private:
        string name;
        int age;
        string ID;
        vector<pair< information_borrow_book ,Book>> list_borrowed_book;
    public:
        Student(string name , int age, string ID){
            this->name=name;
            this-> age=age;
            this->ID =ID;
        }
        void Borrow_book(Library & library,Book book){
            // Get the current time
            time_t borrowTime = time(nullptr);
            index_of_location Index= library.Find_the_book_availabel(book.getTitle(), book.getAuthor(), book.getGenre());
            information_borrow_book infor_bor_book;
            infor_bor_book.time =borrowTime;
            infor_bor_book.Index= Index;
            if(Index.index != -1){
                library.get_ALLBOOK()[Index.genre][Index.title][Index.author][Index.index].Borrow_book();
                pair<information_borrow_book,Book> book1(infor_bor_book, book);
                list_borrowed_book.push_back(book1);
            }    
        }
        void Return_book(Library &  Library, Book book){
            for(int i=0; i< list_borrowed_book.size(); i++){
                if (list_borrowed_book[i].second == book){
                    
                    information_borrow_book inf_book=list_borrowed_book[i].first;

                    //calculate the borrowing time
                    time_t returntime= time(nullptr);
                    time_t borrowtime= inf_book.time;
                    time_t diffSeconds  =difftime(returntime, borrowtime);
                    int diffDays = diffSeconds / (60 * 60 * 24);
                    int diffHours = (diffSeconds / (60 * 60)) % 24;

                    // Output the difference
                    cout << "Days: " << diffDays << endl;
                    cout << "Hours: " << diffHours << endl;
                    Calculate_penalty_money(diffDays, diffHours);
                    
                    // Turn the book in the library to be availale;
                    index_of_location ind_loc= inf_book.Index;
                    Library.get_ALLBOOK()[ind_loc.genre][ind_loc.title][ind_loc.author][ind_loc.index].Return_book();
                    list_borrowed_book.erase(list_borrowed_book.begin()+i);
                }
            }
        }      
};