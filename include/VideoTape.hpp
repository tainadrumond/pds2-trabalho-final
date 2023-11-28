#ifndef VIDEOTAPE_HPP
#define VIDEOTAPE_HPP

#include "Media.hpp"
#include <string>

class VideoTape : public Media
{
private:
    int price = 5;

public:
    VideoTape(std::string title, int copies, int id): Media(id, title, copies, price) {};

    void returnMedia(int rewound);
    std::string getMediaType(); 
};

#endif