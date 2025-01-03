#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book{
    private:
        std::string title;
        std::string author;
        std::string isbn;
    public:
        Book(std::string mytitle, std::string myauthor, std::string myisbn);
        void setTitle(std::string);
        void setAuthor(std::string);
        void setIsbn(std::string);
        std::string getTitle(void);
        std::string getAuthor(void);
        std::string getIsbn(void);
        
};
#endif