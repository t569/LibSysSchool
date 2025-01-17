#include "library.h"


//Function that  Adds a book to the library
void Library::addBook(const BookItem& book)
{
    this->books.emplace_back(book);
}  

// Function that Adds a patron to the library           
void Library::addPatron(const Patron& patron)
{
    this->patrons.emplace_back(patron);   
}   

BookItem* Library::searchBooksByTitle(const std::string& title) 
{
    for(auto& book: this->books)
    {
        if(book.getTitle() == title)
        {
            return &book;
        }
    }
    return nullptr;
}

// Search books by author     
BookItem* Library::searchBooksByAuthor(const std::string& author)
{
    for(auto& book: this->books)
    {
        if(book.getAuthor() == author)
        {
            return &book;
        }
    }
    return nullptr;
}   

// Find a patron by name
Patron* Library::searchPatronByName(const std::string& name)
{
    for(auto& patron: this->patrons)
    {
        if(patron.getName() == name)
        {
            return &patron; // if we get the name return address
        }
    }
    // if it cant find the patron
    return nullptr;
}

void Library::listOverdueBooks() const
{
    std::time_t now = std::time(nullptr);
    for(auto& record: this->patronRecords)
    {
        std::vector<BookItem> myrecord = record.getCheckedOutBooks();
        for(auto& book : myrecord)
        {
            // the book is overdue;
            if(now > parseTime(book.getDueDate()))
            {
                book.printDetails();    // output the details
            }    
        }
    }  
}

void Library::notifyPatronsWithOverdueBooks() const
{
    for(auto& record: this->patronRecords)
    {
        if(record.hasOverdueBooks())
        {
            record.getPatron().setmessage("You have overdue books!");   // might change later
        }
    }
}

bool Library::isBookAvailable(const std::string& isbn) const
{
    for(auto& book: this->books)
    {
        if(book.getIsbn() == isbn)
        {
            if(book.getAvailable())
            {
                return true;
            }
        }
    }
    return false;   // if it defaults
} 

void Library::generateLibraryReport() const
{
    for(auto& book : this->books)
    {
        book.printDetails();    // print the details of all library books
    }
}

/*
void reserveBook(const std::string& isbn, const std::string& patronCardNumber);      
void viewTransactionHistory(const std::string& patronCardNumber) const; 
*/

// Add proper dependencies
void Library::viewTransactionHistory(const std::string& patronCardNumber) const 
{
    for(auto& record : patronRecords)
    {
        if(record.getPatron().getLibraryCardNumber() == patronCardNumber)
            for(auto& history_entry: record.getPatronTransactions())
            {
                record.displayClassicRecord(history_entry); // display the record for a particular patron
            }
    }
    // if nothing was found return null
    return;
}

// Add proper dependencies
void Library::reserveBook(const std::string& isbn, const std::string& patronCardNumber)
{
    // set isAvailable to false first
    // then make it only accessible to said patron
}