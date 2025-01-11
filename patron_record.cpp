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


// Helper Function Parse time
std::time_t parseTime(const std::string& timetoparse)
{
    std::tm dueTimeInfo = {};
    std::istringstream ss(timetoparse);
    ss >> std::get_time(&dueTimeInfo, "%Y-%m-%d");

    std::time_t dueTime = std::mktime(&dueTimeInfo);

    return dueTime;

}
// Function to Check if the patron has overdue books.
bool PatronRecord::hasOverdueBooks()const
{
    std::time_t now = std::time(nullptr);    
    for(auto& book : this->checkedOutBooks)
        {
            if(now > parseTime(book.getDueDate()))
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
    std::time_t now = std::time(nullptr); 
    for(auto& book: this->checkedOutBooks)
    {
        std::time_t duedate = parseTime(book.getDueDate());
        if(now > duedate)
        {
            fees += book.calculateLateFees(static_cast<int>(now - duedate)/ (24 * 60 * 60));
        }
    }
    return fees;
}

std::vector<BookItem> PatronRecord::getCheckedOutBooks() const
{
    return this->checkedOutBooks;
}

int a = 4;