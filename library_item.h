// 3. LibraryItem Class (Base Class)
//  ● Createabase class named LibraryItem representing items available in the library.
//  ● Include the following properties:
//     ○ title
//     ○ isCheckedOut
//     ○ dueDate
//  ● Include member functions:
//     ○ checkOut()
//     ○ returnItem()
//     ○ renewItem(int extraDays)– Extend the due date for an item.
//     ○ markAsLost()– Mark an item as lost and update its status.
//  ● Use encapsulation to protect data members.
#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
class LibraryItem {
private:
    std::string title;
    bool isCheckedOut;
    std::string dueDate;
    bool islost = false;

public:
    LibraryItem(const std::string& title, bool& isCheckedOut , const std::string& dueDate);
    //Getters ans Setters
    std::string getTitle()const;
    bool getIsCheckedOut()const;
    std::string getDueDate(void) const;
    void setTitle(const std::string& newTitle);




    bool checkOut(const std::string& dueDate);
    void returnItem();
    // Function to Extend the due date for an item.
    bool renewItem(int extraDays);
    // Function to Mark an item as lost and update its status.
    void markAsLost();
 };
 #endif // LIBRARY_ITEM_H