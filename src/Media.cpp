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