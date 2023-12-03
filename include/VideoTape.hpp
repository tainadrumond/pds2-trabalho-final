#ifndef VIDEOTAPE_HPP
#define VIDEOTAPE_HPP

#include "Media.hpp"
#include <string>

const int VIDEO_TAPE_PRICE = 5;

class VideoTape : public Media
{
private:
    float const _priceForRewoundDevolution = 2;
    bool const _fixedPrice = true;

public:
    VideoTape(std::string title, int copies, int id) : Media(id, title, copies, VIDEO_TAPE_PRICE, _fixedPrice){};

    float getPrice();
    float getPriceForRewoundDevolution();

    std::string getMediaType();
};

#endif