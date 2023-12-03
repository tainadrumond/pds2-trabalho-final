#include "../include/DVDCategory.hpp"
#include <string>

std::string DVDCategory::getName() {
    return _name;
}

float DVDCategory::getPrice() {
    return _price;
}

bool DVDCategory::hasFixedPrice() {
    return _fixedPrice;
}