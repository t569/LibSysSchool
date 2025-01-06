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
    for(auto& record: this->patronRecords)
    {
        std::vector<BookItem> myrecord = record.getCheckedOutBooks();
        for(auto& book : myrecord)
        {
            // the book is overdue;
            if(record.current_date > book.getDueDate())
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
            // send a message to the patron
        }
    }
}


/*
void generateLibraryReport() const;    
 
void reserveBook(const std::string& isbn, const std::string& patronCardNumber);      
void viewTransactionHistory(const std::string& patronCardNumber) const; 
*/

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