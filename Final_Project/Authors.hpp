#pragma once

#include <string>

class Author {
    std::string firstName_;
    std::string lastName_;
public:
    Author(std::string_view , std::string_view );
    [[nodiscard]] std::string getFirstName() const ;
    [[nodiscard]] std::string getLastName() const ;
};
