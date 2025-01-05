#include "book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
{
    this->title = title;
    this->author = author;
    this->isbn = isbn;
}
void Book::setTitle(const std::string& titleToSet){
    this->title = titleToSet;
}
void Book::setAuthor(const std::string& authorToSet){
    this->author = authorToSet;
}
void Book::setIsbn(const std::string& isbnToSet){
    this->isbn = isbnToSet;
}

std::string Book::getTitle(void) const{
    return this->title;
}
std::string Book::getAuthor(void) const{
    return this->author;
}
std::string Book::getIsbn(void) const{
    return this->isbn;
}