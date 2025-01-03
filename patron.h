#ifndef PATRON_H
#define PATRON_H
#include <string>
class Patron{
    private:
        std::string name;
        int libraryCardNumber;  // this makes more sense lol
    public:
        Patron(std::string name, int libraryCardNumber);
        void updateContactInfo(const std::string& newContactInfo);
        bool canBorrowMoreBooks(int currentBorrowedCount, int maxLimit);
        void setName(const std::string& nameToSet);
        void setLibCardNumber(int cardNoToset);
        std::string getName(void);
        int getLibCardNUmber(void);
};
#endif