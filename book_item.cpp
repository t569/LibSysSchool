#include "book_item.h"
#include <iostream>

BookItem::BookItem(const std::string& title, const std::string& author, const std::string& isbn)
 : LibraryItem(title), author(author), isbn(isbn) {}

std::string BookItem::getAuthor() const { return author; }
void BookItem::setAuthor(const std::string& author) { this->author = author; }

std::string BookItem::getISBN() const { return isbn; }
void BookItem::setISBN(const std::string& isbn) { this->isbn = isbn; }

void BookItem::printDetails() const {
std::cout << "Book Details:\n"
  << "Title: " << getTitle() << 
 << "Author: " << author << 
  << "ISBN: " << isbn << 
  << "Checked Out: " << (isCheckedOut() ? "Yes" : "No") << "\n"
  << "Due Date: " << (isCheckedOut() ? getDueDate() : "N/A") << "\n";
}

double BookItem::calculateLateFees(int daysOverdue) const {
    const double lateFeeRate = 0.50;
    return daysOverdue * lateFeeRate;
}
