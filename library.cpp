#include "library.h"


//Function that  Adds a book to the library
void Library::addBook(const BookItem& book)
{
    this->books.emplace_back(book);
}  

// Function that Adds a patron to the library           
void Library::addPatron(const Patron& patron, const PatronRecord& record)
{
    this->patrons.emplace_back(patron);  
    // also add a patron record
    this->patronRecords.emplace_back(record);
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


void Library::viewTransactionHistory(const std::string& patronCardNumber)
{
    for(auto& record: this->patronRecords)
    {
        if(record.getPatron().getLibraryCardNumber() == patronCardNumber)
        {
            loopAndDump(record);
        }
        else{
            std::cout<<"oooooo"<<std::endl;
        }
    }

}

PatronRecord* Library::getRecordForPatron(Patron* patron)
{
    if(!patron) return nullptr;
    for(size_t i = 0; i < patrons.size(); i++)
        if(patron == &patrons[i]) return &patronRecords[i];
    return nullptr;
}

void loopAndDump(PatronRecord& record)
{
    auto transactions = record.getPatronTransactions();
    for(auto& stuff: transactions)
    {
        record.displayClassicRecord(stuff);
    }
}



// add a book to a patron's reserve record
void Library::reserveBook(const std::string& isbn, const std::string& patronCardNumber)
{
    // get patron first
    Patron* refpatron;
    for(auto patron: this->patrons)
    {
        if(patron.getLibraryCardNumber() == patronCardNumber)
            refpatron = &patron;
    }

    // get the book second
    BookItem* refbook;
    for(auto book: this->books)
    {
        if(book.getIsbn() == isbn)
            refbook = &book;
    }

    // check the reserved count and add it if the count is enough
    if((*refbook).getReservedCount() > 0 && (*refbook).getAvailable())  // this is when its available and it can be reserved
    {
        // check patron records for particular patron 
        for(auto record: this->patronRecords)
        {
            if(record.getPatron().getName() == (*refpatron).getName())
            {
                record.getReservedBooks().emplace_back((*refbook)); // add book to reserved books
            }    
        }

        // decrement the count
        (*refbook).setReservedCount(-1);  // reduces the count by 1
    }

    // then make it only accessible to said patron
}