//  4. BookItem Class (Derived Class)
//  ● Createaderived class named BookItem that inherits from LibraryItem.
//  ● Add properties specific to books:
//     ○ author
//     ○ isbn
//  ● Override appropriate functions for books:
//     ○ printDetails() – Display all details of the book, including availability status.
//     ○ calculateLateFees(int daysOverdue)– Compute the fine for overdue books based on a per-day
//     rate.
#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H
#include "library_item.h"
#include <iostream>
class BookItem : public LibraryItem {
private:
    std::string author;
    std::string isbn;
    bool isAvailable = true;
    double chargePerDay = 12.00;
public:
    // Constructor
    BookItem(const std::string& title, bool& isCheckedOut,
     const int& dueDate, const std::string& author, const std::string& isbn);

    // Getters and Setters
    std::string getAuthor()const;
    void setAuthor(const std::string& newAuthor);
    std::string getIsbn()const;
    void setIsbn(const std::string& newIsbn);
    bool getAvailable() const;
    void setAvailable(bool& new_status);
    double getLateCharge() const;
    void setLateCharge(double&);

    // Function to Display details of the book
    void printDetails()const; 
    // Function to Calculate fine based on overdue days
    double calculateLateFees(int daysOverdue); 
};
#endif // BOOK_ITEM_H