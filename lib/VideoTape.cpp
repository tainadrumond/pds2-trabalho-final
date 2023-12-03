#include "../include/VideoTape.hpp"

#include <random>

VideoTape::VideoTape(int id, std::string title, bool adult) : Media(id, title, adult)
{
    if (std::rand() % 2 == 0)
    {
        _rewound = true;
    }
    else
    {
        _rewound = false;
    }
}

VideoTape::~VideoTape()
{
}

void VideoTape::rewind()
{
    _rewound = true;
}

bool VideoTape::isRewound()
{
    return _rewound;
}

float VideoTape::getRentPrice(int rentDays)
{
    float price = 5;
    if (!_rewound)
    {
        price += 2;
    }
    return price;
}