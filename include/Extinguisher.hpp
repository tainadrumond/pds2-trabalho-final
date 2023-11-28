// Must be used in a vector, inside store.hpp
#ifndef EXTINGUISHER_HPP
#define EXTINGUISHER_HPP

#include <string>
#include <Media.hpp>

class Extinguisher
{
private:
  static int idCounter;

  int daysToExpDate;
  bool type; // 0 for water; 1 for CO2

public:
  Extinguisher(int daysToExpDate, bool type);
  void Extinguisher::refuel();
  int Extinguisher::getDaysToExpDate();
  bool Extinguisher::getType();
};

#endif