#include "library_item.h"

LibraryItem::LibraryItem(const std::string& title, bool& isCheckedOut ,
 const std::string& dueDate):title(title), isCheckedOut(isCheckedOut),dueDate(dueDate){};
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

std::string LibraryItem::getDueDate(void) const{
    return this->dueDate;
}

// Real functions
    
bool LibraryItem::checkOut(const std::string& dueDate){
     if (!this->isCheckedOut) {
       this-> isCheckedOut = true;
        
        // Calculate due date (14 days in hours from now)
        std::time_t now = std::time(nullptr);
        std::time_t dueTime = now + (14 * 24 * 60 * 60 ); // 14 days in seconds
        // Convert to local time structure
        std::tm* dueTimeInfo = std::localtime(&dueTime); 
        
        // Format the date as YYYY-MM-DD using string stream
        std::stringstream ss;
        ss << std::put_time(dueTimeInfo, "%Y-%m-%d");// date format year / month / day
        this->dueDate = ss.str();
        
        return true; // Checkout successful
    }
    return false;  // Checkout failed (already checked out)

}

void LibraryItem::returnItem(){
    this->isCheckedOut = false;
    this->dueDate = " ";
}

// Function to Extend the due date for an item.
bool LibraryItem::renewItem(int extraDays){
    this->dueDate += extraDays;
    return true;
}
    
// Function to Mark an item as lost and update its status.
void LibraryItem::markAsLost(){
    this->islost = true;
}