//This is 1. Book Class
//  ● Createaclass named Book with the following properties:
//      ○ Title
//      ○ Author
//      ○ ISBN(International Standard Book Number)
//  ● Include appropriate constructor, getter and setter methods.
#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book{
private:
    std::string title;
    std::string author;
    std::string isbn;
public:
    // Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn);
    // this->title = title;
    // this->author = author;
    // this->isbn = isbn;
    // Getters and Setters
    void Book::setTitle(const std::string& titleToSet);
    void Book::setAuthor(const std::string& authorToSet);
    void Book::setIsbn(const std::string& isbnToSet);

    std::string Book::getTitle(void) const;
    std::string Book::getAuthor(void) const;
    std::string Book::getIsbn(void) const;
};
#endif // BOOK_H