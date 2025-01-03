#include "patron.h"

Patron::Patron(std::string name, int libraryCardNumber)
{
    this->name = name;
    this->libraryCardNumber = libraryCardNumber;
}

void Patron::updateContactInfo(const std::string& newContactInfo)
{
    this->name = newContactInfo;
}

bool Patron::canBorrowMoreBooks(int currentBorrowedCount, int maxLimit)
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

void Patron::setLibCardNumber(int cardNoToSet)
{
    this->libraryCardNumber = cardNoToSet;
}

std::string Patron::getName(void){
    return this->name;
}

int Patron::getLibCardNUmber(void){
    return this->libraryCardNumber;
}