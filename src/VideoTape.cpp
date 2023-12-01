#include <string>
#include "../include/VideoTape.hpp"

float VideoTape::getPrice() {
    return _price;
}

float VideoTape::getPriceForRewoundDevolution() {
    return _priceForRewoundDevolution;
}

std::string VideoTape::getMediaType() {
    return "FITA";
}
