#include "patron_record.h"



// Function to add a book to the patron's record
 void PatronRecord::addBook(const BookItem& book)
 {
   this->checkedOutBooks.emplace_back(book); 
 }

// Function to remove a book from the patron's record by ISBN
void PatronRecord::removeBook(const std::string& isbn)
{
    int index = 0;
    for(auto& book: this->checkedOutBooks)
    {
        if(book.getIsbn() == isbn)
        {
            break;
        }
        index++;
    }
    this->checkedOutBooks.erase(this->checkedOutBooks.begin() + index);
}
    
//Function to List all books a patron currently has.
void PatronRecord::listCheckedOutBooks()const
{
    for(auto& book: this->checkedOutBooks)
    {
        book.printDetails();
    }
}

// Function to Count the number of books a patron has checked out.
int PatronRecord::getBorrowedBookCount()const
{
    for(auto& book : this->checkedOutBooks)
    {
        std::cout<<book.getIsCheckedOut()<<std::endl;
    }
}
    
// Function to Check if the patron has overdue books.
bool PatronRecord::hasOverdueBooks()const
{
  for(auto& book : this->checkedOutBooks)
    {
        if(this->current_date > book.getDueDate())
        {
            return true;
        }
    }
    return false;  
}
    
// Function to Compute total overdue fees for the patron.
double PatronRecord::calculateTotalLateFees()
{
    double fees = 0;
    for(auto& book: this->checkedOutBooks)
    {
        if(this->current_date > book.getDueDate())
        {
            fees += book.calculateLateFees(current_date - book.getDueDate());
        }
    }
    return fees;
}