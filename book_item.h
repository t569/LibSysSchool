#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H
#include "library_item.h"
class BookItem : public LibraryItem {
private:
    std::string author;
    std::string isbn;
public:
    // Constructor
    BookItem(const std::string& title, bool isCheckedOut, const std::string& dueDate, const std::string& author, const std::string& isbn);
    // Getters and Setters
    std::string getAuthor() const;
    void setAuthor(const std::string& author);
    std::string getISBN() const;
    void setISBN(const std::string& isbn);
  
    // Function to Display details of the book
    void printDetails()const; 
    // Function to Calculate fine based on overdue days
    double calculateLateFees(int daysOverdue)const; 
};
#endif // BOOK_ITEM_H
