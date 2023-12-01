#ifndef VIDEOTAPE_HPP
#define VIDEOTAPE_HPP

#include "Media.hpp"
#include <string>

const int VIDEO_TAPE_PRICE = 5;

class VideoTape : public Media
{
private:
    float _priceForRewoundDevolution = 2;

public:
    VideoTape(std::string title, int copies, int id): Media(id, title, copies, VIDEO_TAPE_PRICE) {};

    int getPrice();
    float getPriceForRewoundDevolution();

    std::string getMediaType(); 
};

#endif