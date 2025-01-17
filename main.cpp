#include <iostream>
#include "library.h"


int main()
{
    Library mylibrary;
    BookItem an_farm("Animal farm",false,"2025-12-11", "George Orwell", "isbn-1234567890");
    Patron greg("greg", "12345", "+234 901 234 56");

    mylibrary.addBook(an_farm);
    mylibrary.addPatron(greg, PatronRecord(&greg));

    PatronRecord& greg_record = *mylibrary.getRecordForPatron(mylibrary.searchPatronByName(greg.getName()));
    mylibrary.generateLibraryReport();
    greg_record.addBook(an_farm);

    std::cout<<"====================\n";
    mylibrary.viewTransactionHistory(greg.getLibraryCardNumber());
    std::cout<<"====================\n";
   
    /*
    
    for(auto& stuff: silas_record.getPatronTransactions())
   {
        std::cout<<stuff.date<<std::endl;
   }

    */
   
    // extra code here
    
}