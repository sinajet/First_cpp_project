#pragma once

#include <utility>
#include <string>
#include <iostream>

#include "Authors.hpp"


class Book {
    int id_;
    std::string title_;
    std::string isbn_;
    Author author_;
public:
    Book(int, std::string_view, std::string_view, Author ) ;
    [[nodiscard]] const std::string & getTitle() const ;
    [[nodiscard]] const Author & getAuthor() const ;
    [[nodiscard]] int getId() const ;
    [[nodiscard]] const std::string & getIsbn() const ;
    friend std::ostream & operator<<(std::ostream & os, const Book & book);
};
