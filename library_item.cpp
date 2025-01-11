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

bool LibraryItem::returnItem(){
    if (isCheckedOut) {
        this -> isCheckedOut = false;
        dueDate = "";
        return true;
    }
    return false;
}

// Function to Extend the due date for an item.
bool LibraryItem::renewItem(int extraDays){
    if (!this->isCheckedOut || this->islost) {
        return false;
    }

    // Parse current due date
    std::tm timeinfo = {};
    std::stringstream ss(dueDate);
    ss >> std::get_time(&timeinfo, "%Y-%m-%d");
    
    // Add extra days
    std::time_t dueTime = std::mktime(&timeinfo);
    dueTime += (extraDays * 24 * 60 * 60);// days , hours,miutes, seconds 
    
    // Format new due date
    std::tm* newDueTime = std::localtime(&dueTime);
    std::stringstream newDueSS;
    newDueSS << std::put_time(newDueTime, "%Y-%m-%d");
    this->dueDate = newDueSS.str();
    
    return true;
}
    
// Function to Mark an item as lost and update its status.
void LibraryItem::markAsLost(){
    this->islost = true;
}