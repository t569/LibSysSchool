#include "book.h"

Book::Book(std::string mytitle, std::string myauthor, std::string myisbn)
{
    this->title = mytitle;
    this->author = myauthor;
    this->isbn = myisbn;
}
void Book::setTitle(std::string titleToSet){
    this->title = titleToSet;
}
void Book::setAuthor(std::string authorToSet){
    this->author = authorToSet;
}
void Book::setIsbn(std::string isbnToSet){
    this->isbn = isbnToSet;
}

std::string Book::getTitle(void){
    return this->title;
}
std::string Book::getAuthor(void){
    return this->author;
}
std::string Book::getIsbn(void){
    return this->isbn;
}