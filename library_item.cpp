#include "library_item.h"
#include <ctime> // For time functions
#include <sstream> // For string stream operations
#include <iomanip> // For date/time formatting

LibraryItem::LibraryItem(const std::string& itemTitle)
    : title(itemTitle), isCheckedOut(false), dueDate("") {}
LibraryItem::LibraryItem(const std::string& title, bool& isCheckedOut , const std::string& dueDate);

std::string LibraryItem::getTitle() const{ 
    return title; 
}
bool LibraryItem::getIsCheckedOut() const { 
    return isCheckedOut;
}
std::string LibraryItem::getDueDate() const { 
    return dueDate; 
}

bool LibraryItem::checkOut() {
    if (!isCheckedOut) {
       this-> isCheckedOut = true;
        
        // Calculate due date (14 days in hours from now)
        std::time_t now = std::time(nullptr);
        std::time_t dueTime = now + (14 * 24 * 60 * 60 ); // 14 days in seconds
        // Convert to local time structure
        std::tm* dueTimeInfo = std::localtime(&dueTime); 
        
        // Format the date as YYYY-MM-DD using string stream
        std::stringstream ss;
        ss << std::put_time(dueTimeInfo, "%Y-%m-%d");// date format year / month / day
        dueDate = ss.str();
        
        return true; // Checkout successful
    }
    return false;  // Checkout failed (already checked out)
}

// Method to return an item
bool LibraryItem::returnItem() {
    if (isCheckedOut) {
        this -> isCheckedOut = false;
        dueDate = "";
        return true;
    }
    return false;
}
// Method to renew an item with additional day
bool LibraryItem::renewItem(int extraDays) {
    if (!isCheckedOut || dueDate == "LOST") {
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
    dueDate = newDueSS.str();
    
    return true;
}

// Method to mark an item as lost
void LibraryItem::markAsLost() {
    isCheckedOut = true;
    dueDate = "is LOST";
}

