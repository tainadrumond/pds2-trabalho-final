#include <string>
#include <Extinguisher.hpp>

Extinguisher::Extinguisher(int daysToExpDate, bool type): daysToExpDate(daysToExpDate), type(type)
{

}
void Extinguisher::refuel(){
  daysToExpDate = 0;
}
int Extinguisher::getDaysToExpDate(){
  return(daysToExpDate);
}
bool Extinguisher::getType(){
  return(type);
}