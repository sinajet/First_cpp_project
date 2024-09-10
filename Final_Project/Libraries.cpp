#include "Libraries.hpp"

void Library::addBook(int id, const Book &book) {
    this->books_.emplace(id, book);
}
std::optional<Book> Library::searchBookId(int id) {
    if (books_.empty()) return std::nullopt;
    auto it = books_.find(id);
    if (it != books_.end()) {
        return it->second;
    }
    else {
        return std::nullopt;
    }
}
std::optional<Book> Library::searchBookTitle(std::string_view title) {
    for (auto & [id, book] : books_) {
        if (book.getTitle() == title) return book;
    }
    return std::nullopt;
}
void Library::removeElementId(int id) {
    auto it = books_.find(id);
    if (it != books_.end())
        books_.erase(it);
}
std::vector<Book> Library::getAllBooks() const {
    std::vector<Book> books;
    books.reserve(books_.size());
    for (auto & [id, book] : books_) {
        books.emplace_back(book);
    }
    return books;
}
