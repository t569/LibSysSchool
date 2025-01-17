//  2. Patron Class
//  ● Createaclass named Patron with the following properties:
//      ○ Name
//      ○ Library Card Number
//  ● Include the following functions:
//      ○ updateContactInfo(const std::string& newContactInfo)– Update the patron’s contact details.
//      ○ canBorrowMoreBooks(int currentBorrowedCount, int maxLimit)– Check if the patron can
//      borrow more books.
//  ● Include appropriate constructor, getter and setter methods.
#ifndef PATRON_H
#define PATRON_H
#include <string>

class Patron {
private:
    std::string name;
    std::string libraryCardNumber;
    std::string contactInfo;
public:
    //Constuctor
    Patron(const std::string& name, const std::string& libraryCardNumber, const std::string& contactInfo);
    //Getters ans Setters
    std::string getName()const{
        return name;
    }
    void setName(const std::string& newName){
        name=newName;
    }

    std::string getLibraryCardNumber()const{
        return libraryCardNumber;
    }
    void setLibraryCardNumber(const std::string& newLibraryCardNumber){
        libraryCardNumber=newLibraryCardNumber;
    }

    std::string getContactInfo()const{
        return  contactInfo;
    }
    void setContactInfo(const std::string& newContactInfo){
        contactInfo=newContactInfo;
    }
    //Function to Update the patron’s contact details.
    void updateContactInfo(const std::string& newContactInfo){
        setContactInfo(newContactInfo);
    }
    //Function to Check if the patron can borrow more books.
    bool canBorrowMoreBooks(int currentBorrowedCount, int maxLimit)const;

};
#endif //PATRON_H