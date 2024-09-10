#include "Books.hpp"
#include "numeric"

Book::Book(int id, std::string_view title, std::string_view isbn, Author author) :
id_(id),
isbn_(isbn),
title_(title),
author_(std::move(author)) {}

const std::string &Book::getTitle() const {
    return this->title_;
}

const Author &Book::getAuthor() const {
    return this->author_;
}

int Book::getId() const {
    return this->id_;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    std::string x;
    os << "Title : " << book.title_ <<" | ISBN : " << book.isbn_ << " | Author : " << book.author_.getFirstName() << " , " << book.author_.getLastName();
    return os;
}

const std::string &Book::getIsbn() const {
    return this->isbn_;
}
