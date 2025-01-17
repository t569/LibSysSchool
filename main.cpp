#include <iostream>
#include "library.h"



int main()
{
    Library mylibrary;
    BookItem an_farm("Animal farm",false,"2025-12-11", "George Orwell", "isbn-1234567890");
    Patron silas("silas", "12345", "+234 901 234 56");
    mylibrary.addBook(an_farm);
    mylibrary.addPatron(silas);
    mylibrary.generateLibraryReport();

    // extra code here

}