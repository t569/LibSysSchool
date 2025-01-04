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
class LibraryItem {
private:
    std::string title;
    bool isCheckedOut;
    std::string dueDate;
public:
    //Constuctor
    LibraryItem(const std::string& title, bool& isCheckedOut , const std::string& dueDate);
    //Getters ans Setters
    std::string getTitle()const{
        return Title;
    }
    void setTitle(const std::string& newTitle){
        title=newTitle;
    }
    bool getIsCheckedOut()const{
        return isCheckedOutr;
    }
    void IsCheckedOut(bool newIsCheckedOut){
        isCheckedOut=newIsCheckedOut;
    }
    std::string DueDate()const{
        return  dueDate;
    }
    void setDueDate(const std::string& newDueDate){
        dueDate=newDueDate;
    }
    void checkOut(const std::string& dueDate);
    void returnItem();
    // Function to Extend the due date for an item.
    int renewItem(int extraDays);
    // Function to Mark an item as lost and update its status.
    void markAsLost();
 };
 #endif // LIBRARY_ITEM_H