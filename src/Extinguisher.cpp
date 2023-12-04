#include <string>
#include "../include/Extinguisher.hpp"

void Extinguisher::refuel()
{
  _daysToExpDate = 0;
}
int Extinguisher::getDaysToExpDate()
{
  return (_daysToExpDate);
}
bool Extinguisher::getType()
{
  return (_type);
}