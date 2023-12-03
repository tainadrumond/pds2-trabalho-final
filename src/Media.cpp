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
void Media::addRating(int rating)
{
  this->_sumRating += rating;
  this->_numRating++;
}
float Media::getAverageRating()
{
  if (this->_numRating == 0)
    return (0);
  return (this->_sumRating / this->_numRating);
}