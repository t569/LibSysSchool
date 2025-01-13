#include "book_item.h"

BookItem::BookItem(const std::string& title, bool isCheckedOut,
     const std::string& dueDate, const std::string& author, const std::string& isbn)
    : LibraryItem(title, isCheckedOut,dueDate), author(author), isbn(isbn)
    { }     // ORMOR E CHORKE!

// Find a way to incorporate book.h 

// Getters and Setters
std::string BookItem::getAuthor()const{
        return this->author;
    }

void BookItem::setAuthor(const std::string& newAuthor){
        this->author=newAuthor;
    }

std::string BookItem::getIsbn()const{
        return this->isbn;
    }

void BookItem::setIsbn(const std::string& newIsbn){
        this->isbn=newIsbn;
    }

bool BookItem::getAvailable() const 
{
    return this->isAvailable;   
}

void BookItem::setAvailable(bool& new_status){
    this->isAvailable = new_status;
}

double BookItem::getLateCharge() {
    return this->chargePerDay;
}

void BookItem::setLateCharge(double& new_charge)
{
    this->chargePerDay = new_charge;
}

void BookItem::printDetails()const{
    std::cout<<"Title: "<<LibraryItem::getTitle()<<std::endl;    
    std::cout<<"Due Date: "<<LibraryItem::getDueDate()<<std::endl;
    std::cout<<"Checked Out: "<<LibraryItem::getIsCheckedOut()<<std::endl;
    std::cout<<"Author: "<<getAuthor()<<std::endl;
    std::cout<<"Isbn: "<<getIsbn()<<std::endl;
    std::cout<<"Avaialble: "<<getAvailable()<<std::endl;
}

// Function to Calculate fine based on overdue days
double BookItem::calculateLateFees(int daysOverdue)
    {
        return this->getLateCharge() * daysOverdue;
    }