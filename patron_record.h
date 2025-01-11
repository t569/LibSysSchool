//  5. PatronRecord Class
//  ● Create a class named PatronRecord that keeps track of the books a patron has checked out.
//  ● Include functions for adding and removing books from a patron's record.
//  ● Additional functionalities:
//     ○ Checked-OutBooks Management:
//         ■ listCheckedOutBooks()– List all books a patron currently has.
//         ■ getBorrowedBookCount()– Count the number of books a patron has checked out.
//         ■ hasOverdueBooks()– Check if the patron has overdue books.
//     ○ LateFees:
//         ■ calculateTotalLateFees()– Compute total overdue fees for the patron.
#ifndef PATRON_RECORD_H
#define PATRON_RECORD_H
#define CURR_DATE 30
#include <vector>
#include <iostream>     // this might bre redundant and a bad choice lol
#include "book_item.h"
#include "patron.h"
class PatronRecord {
private:
    std::vector<BookItem> checkedOutBooks;
    Patron unique_patron;       // patron being referred to

    
public:
    int current_date = CURR_DATE;       // to be set or implemented

    // Function to add a book to the patron's record
    void addBook(const BookItem& book);
    // Function to remove a book from the patron's record by ISBN
    void removeBook(const std::string& isbn);
    //Function to List all books a patron currently has.
    void listCheckedOutBooks()const;
    // Function to Count the number of books a patron has checked out.
    int getBorrowedBookCount()const;
    // Function to Check if the patron has overdue books.
    bool hasOverdueBooks()const;
    // Function to Compute total overdue fees for the patron.
    double calculateTotalLateFees();


    // Helper function
    std::time_t parseTime(const std::string& timetoparse) const;

    std::vector<BookItem> getCheckedOutBooks() const;
};
#endif // PATRON_RECORD_H
