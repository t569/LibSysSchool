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
    void Patron::updateContactInfo(const std::string& newContactInfo);
    bool Patron::canBorrowMoreBooks(int currentBorrowedCount, int maxLimit) const;
    void Patron::setName(const std::string& nameToSet);
    void Patron::setLibraryCardNumber(const std::string& newLibraryCardNumber);
    void Patron::setmessage(const std::string& message);
    std::string Patron::getName(void) const;
    std::string Patron::getLibraryCardNumber(void) const;
    std::string Patron::getmessage(void);

};
#endif //PATRON_H