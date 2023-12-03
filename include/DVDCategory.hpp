#ifndef DVDCATEGORY_HPP
#define DVDCATEGORY_HPP

#include <string>

class DVDCategory
{
private:
    std::string _name;
    float _price;
    bool _fixedPrice;

public:
    DVDCategory(std::string name, float price, bool fixedPrice) : _name(name), _price(price), _fixedPrice(fixedPrice){};

    std::string getName();
    float getPrice();
    bool hasFixedPrice();
};

#endif