#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<vector>
#include<list>
#include "Library.h"
#include "Student.h"
using namespace std;


#include <iostream>
int main(){
    // Library Library;
    
    // index_of_location i=Library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    // // Libary.Find_book_with_special_info("-1","-1","fiction");
    // Book book1("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    // Library.Borrow_in_lib(book1);
    // index_of_location j=Library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    // Library.Return_in_lib(book1);
    // index_of_locatio h =Library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    

    // Library.Find_book_with_special_info("To Kill a Mockingbird","  Harper Lee  ","-1");


    Library  library;
    Library & libref= library;
    Book book("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    Student student1("Chi","22chi.nh","V20220000");
    Book book2("Pride and Prejudice "," Jane Austen "," Romance");
    student1.Borrow_book_student(libref,book2);
    student1.Borrow_book_student(libref, book);
    // information_borrow_book infbook=student1.list_book_borrow()[0].first;
    // index_of_location indloca= infbook.Index;
    student1.get_list_book_borrow_student();
    cout << "after borrow \n";
    library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    student1.Return_book_student(libref,book);
    student1.get_list_book_borrow_student();
    library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    
    
    /*test find student*/
    // Library library;
    // Library & libref= library;
    // Manage_student Student_management;
    // Book book("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    // Student student1("Chi","22chi.nh","V20220000");
    // Student_management.add_student_borrow_book(student1);
    // // Student_management.print_out_all_student_who_borrow_book();
    // // Student_management.remove_student_borrow_book(student1);
    // // Student_management.print_out_all_student_who_borrow_book();
    // Student_management.test_find();
    // Student_management.Find_student_borrow_book(libref, book);


    // Library library;
    // Library & libref= library;
    // // library.Find_book_with_special_info("-1","-1","fiction");

    // Manage_student student_management;
   
    // student_management.Take_infor_student_book(libref);

    return 0;
}