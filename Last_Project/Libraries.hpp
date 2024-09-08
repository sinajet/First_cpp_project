#pragma once
#include <optional>
#include <unordered_map>
#include <vector>
#include <string>

#include "Books.hpp"

class Library {
    std::unordered_map<int, Book> books_;
public:
    void addBook(int, const Book & book) ;
    std::optional<Book> searchBookId(int) ;
    std::optional<Book> searchBookTitle(std::string_view) ;
    void removeElementId(int) ;
    [[nodiscard]] std::vector<Book> getAllBooks() const ;
};
