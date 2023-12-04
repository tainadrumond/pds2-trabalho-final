// Must be used in a vector, inside store.hpp
#ifndef EXTINGUISHER_HPP
#define EXTINGUISHER_HPP

#include <string>

class Extinguisher
{
private:
  static int _idCounter;

  int _daysToExpDate;
  bool _type; // 0 for water; 1 for CO2

public:
/**
* @brief Método que constrói um extintor.
*/
  Extinguisher(int daysToExpDate, bool type) : _daysToExpDate(daysToExpDate), _type(type){};
/**
* @brief Método que recarrega o extintor.
*/
  void refuel();
/**
* @brief Método informa os dias para trocar o extintor.
*
* @return Int de dias para expirar.
*/
  int getDaysToExpDate();
/**
* @brief Método informa os dias para trocar o extintor.
*
* @return Booleano do tipo.
*/
  bool getType();
};

#endif