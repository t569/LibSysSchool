#include "patron.h"

Patron::Patron(const std::string& name, const std::string& libraryCardNumber, const std::string& contactInfo)
{
    this->name = name;
    this->libraryCardNumber = libraryCardNumber;
    this->contactInfo = contactInfo;
}

void Patron::updateContactInfo(const std::string& newContactInfo)
{
    this->name = newContactInfo;
}

bool Patron::canBorrowMoreBooks(int currentBorrowedCount, int maxLimit) const
{
    if (currentBorrowedCount > maxLimit)
    {
        return false;
    }
    return true;
}

void Patron::setName(const std::string& nameToSet)
{
    this->name = nameToSet;
}

void Patron::setLibraryCardNumber(const std::string& newLibraryCardNumber)
{
    this->libraryCardNumber = newLibraryCardNumber;
}

std::string Patron::getName(void) const{
    return this->name;
}

std::string Patron::getLibraryCardNumber(void) const{
    return this->libraryCardNumber;
}

std::string Patron::getmessage()
{
    return this->messages;
}

void Patron::setmessage(const std::string& message)
{
    // append the message on 
    this->messages += message;
}