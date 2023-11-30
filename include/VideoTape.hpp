#ifndef VIDEOTAPE_HPP
#define VIDEOTAPE_HPP

#include "Media.hpp"
#include <string>

class VideoTape : public Media
{
private:
    int _price = 5;
    float _priceForRewoundDevolution = 2;

public:
    VideoTape(std::string title, int copies, int id): Media(id, title, copies, _price) {};

    int getPrice();
    float getPriceForRewoundDevolution();

    std::string getMediaType(); 
};

#endif