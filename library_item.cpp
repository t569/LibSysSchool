#include "library_item.h"

LibraryItem::LibraryItem(const std::string& title, bool& isCheckedOut ,
 const int& dueDate):title(title), isCheckedOut(isCheckedOut),dueDate(dueDate){};
    //Getters ans Setters
 
//Getters ans Setters
std::string LibraryItem::getTitle()const{
    return this->title;
}
    
bool LibraryItem::getIsCheckedOut()const{
    return this->isCheckedOut;
}

void LibraryItem::setTitle(const std::string& newTitle){
    this->title = newTitle;
}

int LibraryItem::getDueDate(void) const{
    return this->dueDate;
}

// Real functions
    
void LibraryItem::checkOut(const int& dueDate){
    this->isCheckedOut = true;
    this->dueDate = dueDate;

}

void LibraryItem::returnItem(){
    this->isCheckedOut = false;
    this->dueDate = 0;
}

// Function to Extend the due date for an item.
int LibraryItem::renewItem(int extraDays){
    this->dueDate += extraDays;
    return this->dueDate;
}
    
// Function to Mark an item as lost and update its status.
void LibraryItem::markAsLost(){
    this->islost = true;
}