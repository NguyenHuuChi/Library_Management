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
    Library Library;
    
    index_of_location i=Library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    // Libary.Find_book_with_special_info("-1","-1","fiction");
    cout <<i.index;

    // Library  library;
    // Library & libref= library;
    // Book book("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    // Student student1("Chi",20,"V20220000");
    // student1.Borrow_book(libref, book);
    // information_borrow_book infbook=student1.list_book_borrow()[0].first;
    // index_of_location indloca= infbook.Index;
    // library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    
    return 0;
}