#include "../include/Media.hpp"
int Media::_idCounter = 0;

int Media::getId()
{
  return (this->_id);
}
std::string Media::getTitle()
{
  return (this->_title);
}
int Media::getCopies()
{
  return (this->_copies);
}
float Media::getPrice()
{
  return (this->_price);
}
bool Media::hasFixedPrice()
{
  return _fixedPrice;
}

void Media::addRating(int rating)
{
  _sumRating += rating;
  _numberOfRatings++;
}

float Media::getRating()
{
  if (_numberOfRatings == 0)
    return 0;
  return (float)_sumRating / _numberOfRatings;
}