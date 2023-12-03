// Must be used in a vector, inside store.hpp
#ifndef EXTINGUISHER_HPP
#define EXTINGUISHER_HPP

#include <string>
#include <Media.hpp>

class Extinguisher
{
private:
  static int _idCounter;

  int _daysToExpDate;
  bool _type; // 0 for water; 1 for CO2

public:
  Extinguisher(int daysToExpDate, bool type) : _daysToExpDate(daysToExpDate), _type(type){};
  void refuel();
  int getDaysToExpDate();
  bool getType();
};

#endif