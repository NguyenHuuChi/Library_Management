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
#include <algorithm>
#include"Library.h"
#include "Student.h"
using namespace std;

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
string Student :: get_name(){
    return name;
}
string Student :: get_ID(){
    return ID;
};
string Student :: get_Email(){
    return Email;
}
void Student :: get_information(){
    cout << "Name : " << name <<" Email : " << Email << " Student ID : " << ID << "\n";
}
bool Student :: operator==(const Student & other)const{
    return ID == other.ID;
};
vector<pair< information_borrow_book ,Book>> Student ::  list_book_borrow(){
    return list_borrowed_book;
}
Student :: Student(string name , string Email, string ID){
    this->name=name;
    this-> Email=Email;
    this->ID =ID;
}

// This function will find the location of book in library, change the state of book in the library
void Student :: Borrow_book(Library & library,Book book){
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
};

// This function will change the state of the book in the library
void Student:: Return_book_student(Library &  Library, Book book){
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


// define the Manage_student class
void Manage_student:: Find_student_borrow_book(Library& library,Book book){
    for(int i=0; i<List_book_is_related_to_ID.size(); i++){
        string title =List_book_is_related_to_ID[i].first;
        string ID=List_book_is_related_to_ID[i].second;
        if(title== book.getTitle()){
            for(int j =0; j < List_student_borrow_book.size(); j++){
                if(ID== List_student_borrow_book[i].get_ID()){
                    List_student_borrow_book[i].get_information();
                }
            }
        }
    }
};
void Manage_student:: History_borrow_and_return_book(const string& a) {
    ofstream file("History.out", ios::app); // Open the file in append mode

    if (file.is_open()) {
        file << a << endl; // Write the string to the file
        file.close(); // Close the file
    } else {
        cout << "Failed to open the file." << endl;
    }
}
void Manage_student :: Take_infor_student_book(Library & library ){
    cout << "Enter your information : \n";
    cout << "Enter your name : ";
    string name;
    cin >> name;
    cout << "Enter your student ID :";
    string ID;
    cin >> ID;
    cout << "Enter your Email :";
    string Email;
    cin >> Email;
    Student student_ob(name, Email, ID);
    cout << "You want to borrow or return book ?";
    cout << "1: borrow book ! \n 2: Return book ! \n 3: Quit !";
    int check_borrow_return;
    cin >> check_borrow_return;
    if(check_borrow_return== 1){
        cout << "Which book you want to find ?";
        string title;
        string author;
        string genre;
        cout << "The title :";
        getline(cin , title);
        cout << "The Author :";
        getline(cin,author);
        cout << " The Genre: ";
        getline(cin , author);
        if (title.empty() ) title="-1";
        if (author.empty()) author="-1";
        if (genre.empty()) genre ="-1";
        vector<Book> List_book_available= library.Find_book_with_special_info(title, author, genre);
        while(true){
            int num ;
            cout <<" You want to find which book ?";
            cin >> num;
            while (num >= List_book_available.size()){
                cout << "Enter the number which is smaller than "<< List_book_available.size();
                cin >> num;
            }
            cout << "You want to borrow the book" ;
            Book book1 =List_book_available[num];
            book1.get_information();
            cout << "1 : Yes \n 2 : No";
            int check_borrow;
            cin >> check_borrow;
            if(check_borrow == 1){
                student_ob.Borrow_book(library,book1 );
                pair<string,string> book_related_to_id(title, ID);
                List_book_is_related_to_ID.push_back(book_related_to_id);
                // if(find(student_ob: List_student_borrow_book))
                // List_student_borrow_book.push_back(student_ob);
                auto it = find(List_student_borrow_book.begin(), List_student_borrow_book.end(), student_ob);

                if (it == List_student_borrow_book.end()) {
                   List_student_borrow_book.push_back(student_ob); 
                } 
                

                // append into the History file
                string A= student_ob.get_name()+" , The student ID is "+ student_ob.get_ID()+
                "borrow the book :" + book1.getTitle();
                History_borrow_and_return_book(A);

                break;
            } 
        }
    } else if(check_borrow_return==2){
        cout << "Which book you want to return :";
        for(int i=0; i < List_student_borrow_book.size(); i++){
            if(List_student_borrow_book[i] == student_ob){
                while (true){
                    cout << "Which books you want to return ?";
                    for (int j=0; j < List_student_borrow_book[i].list_book_borrow().size(); j++){
                        cout <<j <<": ";
                        List_student_borrow_book[i].list_book_borrow()[j].second.get_information();
                    }
                    int remove_book;
                    cin >> remove_book;

                    // make sure the useer input the small 
                    if(remove_book>=0){
                        while(remove_book >= List_student_borrow_book[i].list_book_borrow().size()){
                            cout <<" Enter the number is smaller than " << List_student_borrow_book[i].list_book_borrow().size() <<": ";
                            cin >> remove_book;
                        }
                        // return in the library
                        Book book1= List_student_borrow_book[i].list_book_borrow()[remove_book].second;
                        List_student_borrow_book[i].Return_book_student(library,book1);
                        
                        List_student_borrow_book[i].list_book_borrow().erase(List_student_borrow_book[i].list_book_borrow().begin()+remove_book);
                        if (List_student_borrow_book[i].list_book_borrow().size()<=0){
                            List_student_borrow_book.erase(List_student_borrow_book.begin()+i);

                        }
                        // append into the History file
                        string A= student_ob.get_name()+" , The student ID is "+ student_ob.get_ID()+
                        "return the book :" + List_student_borrow_book[i].list_book_borrow()[remove_book].second.getTitle();
                        History_borrow_and_return_book(A);
                        break;
                    }
                    
                }
                break;
            }
        }
    }
    
}
