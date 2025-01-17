#include "patron_record.h"


struct ClassicRecord
{
    std::string date;                        // date the action was taken 
    std::string patronName;                  // name of the patron
    std::string bookName;                    // name of the book
    Action myaction;
};

// Function to add a book to the patron's record
 void PatronRecord::addBook(const BookItem& book)
 {
   this->checkedOutBooks.emplace_back(book);


   // change date later
   ClassicRecord record_to_add = {__DATE__,this->getPatron().getName(), book.getTitle(), borrow};
   this->patronTransactions.emplace_back(record_to_add);
 }

// Function to remove a book from the patron's record by ISBN
void PatronRecord::removeBook(const std::string& isbn)
{
    int index = 0;
    const BookItem* myrefbook;
    for(auto& book: this->checkedOutBooks)
    {
        if(book.getIsbn() == isbn)
        {
            myrefbook = &book;
            break;
        }
        index++;
    }
    this->checkedOutBooks.erase(this->checkedOutBooks.begin() + index);

    // change date later, add it to the records
    ClassicRecord record_to_add = {__DATE__,this->getPatron().getName(), (*myrefbook).getTitle(), return_from_borrow};
    this->patronTransactions.emplace_back(record_to_add);
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
    int book_count = 0;
    for(auto& book : this->checkedOutBooks)
    {
        if(book.getIsCheckedOut())
        {
            book_count++;
        }
    }
    return book_count;
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

Patron PatronRecord::getPatron() const
{
    return this->unique_patron;
}
int a = 4;

std::vector<ClassicRecord> PatronRecord::getPatronTransactions() const
{
    return this->patronTransactions;
}

void PatronRecord::displayClassicRecord(ClassicRecord myrecord) const
{
    std::cout<<"Date    :"<<myrecord.date<<std::endl;
    std::cout<<"Name    :"<<myrecord.patronName<<std::endl;
    std::cout<<"Book    :"<<myrecord.bookName<<std::endl;
    std::cout<<"IT WAS  :"<<myrecord.myaction<<std::endl;
    std::cout<<'\n'<<std::endl;
}
