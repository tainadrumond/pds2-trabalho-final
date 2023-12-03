#include "../include/Media.hpp"

Media::Media(int id, std::string title, bool adult)
{
    _id = id;
    _title = title;
    _adult = adult;
    _sumRating = 0;
    _countRating = 0;
}

Media::~Media()
{
}

int Media::getId()
{
    return _id;
}

std::string Media::getTitle()
{
    return _title;
}

bool Media::isAdult()
{
    return _adult;
}

void Media::addRating(int rating)
{
    _sumRating += rating;
    _countRating++;
}

float Media::getRating()
{
    if (_countRating == 0)
    {
        return 0;
    }
    return _sumRating / _countRating;
}