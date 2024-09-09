#include "Authors.hpp"

Author::Author(std::string_view firstName,std::string_view lastName) : firstName_(firstName),
lastName_(lastName){}
std::string Author::getFirstName() const {
    return this->firstName_;
}

std::string Author::getLastName() const {
    return this->lastName_;
}


