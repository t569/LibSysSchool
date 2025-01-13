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

    // notifications message
    std::string messages;
public:
    //Constuctor
    Patron(const std::string& name, const std::string& libraryCardNumber, const std::string& contactInfo);


    //Getters ans Setters
    void updateContactInfo(const std::string& newContactInfo);
    bool canBorrowMoreBooks(int currentBorrowedCount, int maxLimit) const;
    void setName(const std::string& nameToSet);
    void setLibraryCardNumber(const std::string& newLibraryCardNumber);
    void setmessage(const std::string& message);
    std::string getName(void) const;
    std::string getLibraryCardNumber(void) const;
    std::string getmessage(void);

};
#endif //PATRON_H