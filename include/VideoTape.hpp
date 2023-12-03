#ifndef VIDEOTAPE_HPP
#define VIDEOTAPE_HPP

#include "Media.hpp"

class VideoTape : public Media
{
private:
    bool _rewound;

public:
    VideoTape(int id, std::string title, bool adult);
    ~VideoTape();

    void rewind();
    bool isRewound();

    float getRentPrice(int rentDays) override;
};

#endif