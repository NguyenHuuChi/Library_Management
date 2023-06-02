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
using namespace std;


#include <iostream>
int main(){
    Library Library;
    
    Library.Find_the_book_availabel("To Kill a Mockingbird" ," Harper Lee "," Fiction");
    // Libary.Find_book_with_special_info("-1","-1","fiction");
    
    return 0;
}