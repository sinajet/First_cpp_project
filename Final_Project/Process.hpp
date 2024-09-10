#pragma once

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <limits>

#include "Authors.hpp"
#include "Books.hpp"
#include "Libraries.hpp"


class Process {
    std::unordered_map<int, Author> authors_;
    Library library_;
public:
    [[noreturn]] void run() ;
private:
    static void showMenu() ;
    void handleChoice(int choice) ;
    void createAuthor() ;
    void createBook() ;
    void findBookId() ;
    void findBookTitle() ;
    void removeBookId() ;
    void showAllBooks() ;
    void exportToFile() ;
    void writeToFile(const std::basic_string<char>& fileName) ;
    static void nextPage();
};
