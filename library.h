// 6. Library Class
//  ● Createaclass named Library that manages a collection of books and patrons.
//  ● Include functions for adding books and patrons to the library.
//  ● Implement borrowing and returning books, updating patron records.
//  ● Additional functionalities:
//     ○ SearchFunctionality:
//         ■ searchBooksByTitle(const std::string& title)– Locate books by title.
//         ■ searchBooksByAuthor(const std::string& author)– Locate books by author.  
//         ■ searchPatronByName(const std::string& name)– Find patrons by name.
//     ○ OverdueManagement:
//         ■ listOverdueBooks()– Display all overdue books.
//         ■ notifyPatronsWithOverdueBooks()– Send notifications to patrons with overdue books.
//     ○ ReportGeneration:
//         ■ generateLibraryReport()– Provide a summary of the library's current state, includingavailable and checked-out books.
//     ○ BookAvailability and Reservations:
//         ■ isBookAvailable(const std::string& isbn)– Check if a book is available for borrowing.
//         ■ reserveBook(const std::string& isbn, const std::string& patronCardNumber)– Allow patrons to reserve a book.
//     ○ Transaction History:
//     ■ viewTransactionHistory(const std::string& patronCardNumber)– Display the borrowing and returning history of a patron.
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book_item.h"
#include "patron.h"
#include "patron_record.h"

class Library {
private:
    std::vector<BookItem> books;               
    std::vector<Patron> patrons;               
    std::vector<PatronRecord> patronRecords;  
    std::vector<std::string> LibraryRecords;
public:
    // Functions for managing books and patrons, borrowing and returning books
    //Function that  Adds a book to the library
    void addBook(const BookItem& book);  
    // Function that Adds a patron to the library           
    void addPatron(const Patron& patron);       
    // Function that Borrow a book for a patron   
    bool borrowBook(const std::string& isbn, const std::string& patronCardNumber);  
    // Function that Return a borrowed book
    bool returnBook(const std::string& isbn, const std::string& patronCardNumber); 
    

    // Search functionality
    // Search books by title
    BookItem* searchBooksByTitle(const std::string& title); 
    // Search books by author     
    BookItem* searchBooksByAuthor(const std::string& author);    
    // Find a patron by name
    Patron* searchPatronByName(const std::string& name);                          


    // Overdue Management
    // List all overdue books
    void listOverdueBooks() const;    
    // Notify patrons with overdue books    
    void notifyPatronsWithOverdueBooks() const; 

    // Report Generation
    //To  Generate a summary of available and checked-out books
    void generateLibraryReport() const;    

    // Book Availability and Reservations
    // To Check if a book is available
    bool isBookAvailable(const std::string& isbn) const;  
    // To Reserve a book for a patron
    void reserveBook(const std::string& isbn, const std::string& patronCardNumber);  

    // Transaction History
    // To View the borrowing and returning history of a patron
    void viewTransactionHistory(const std::string& patronCardNumber) const;

};
#endif // LIBRARY_H