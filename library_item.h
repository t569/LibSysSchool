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
class LibraryItem {
private:
    std::string title;
    bool isCheckedOut;
    int dueDate;
    bool islost = false;

public:
    LibraryItem(const std::string& title, bool& isCheckedOut , const int& dueDate);
    //Getters ans Setters
    std::string getTitle()const;
    bool getIsCheckedOut()const;
    void setTitle(const std::string& newTitle);




    void checkOut(const int& dueDate);
    void returnItem();
    // Function to Extend the due date for an item.
    int renewItem(int extraDays);
    // Function to Mark an item as lost and update its status.
    void markAsLost();
 };
 #endif // LIBRARY_ITEM_H