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
void deleteFileContent(const string& filename) { //delete the file content
    ofstream file(filename, ios::trunc); // Open the file in write mode, truncating existing content

    if (file.is_open()) {
        file.close(); // Close the file to delete its content
    }
}
int main(){

    Library library; //create an object from  library
    Library & libref= library;

    Manage_student student_management; 
   
    student_management.Take_infor_student_book(libref);//take the input
    while (true){
        cout << "You want to login ?\n";
        cout << " 1 : yes \n 2 : no";
        int check;
        cin >> check;
        switch (check)
        {
        case 1:
            student_management.Take_infor_student_book(libref); 
            break;
        
        case 2:
            break;
        } ;
        
        if (check==2){deleteFileContent("History.out"); break;}; //delete the file content when end the program
    }


    return 0;
}