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
    std::string getTitle()const{
        return title;
    }
    void setTitle(const std::string& newTitle){
        title=newTitle;
    }
    std::string getAuthor()const{
        return author;
    }
    void setAuthor(const std::string& newAuthor){
        author=newAuthor;
    }std::string getIsbn()const{
        return isbn;
    }
    void setIsbn(const std::string& newIsbn){
        isbn=newIsbn;
    }
};
#endif // BOOK_H