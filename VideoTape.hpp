#ifndef VIDEOTAPE_HPP
#define VIDEOTAPE_HPP

#include "Media.hpp"
#include <string>

class VideoTape : public Media
{
private:
    bool _rewound;

public:
    VideoTape(std::string title, int copies, bool rewound);
};

#endif