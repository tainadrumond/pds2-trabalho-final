#ifndef DVDCATEGORY_HPP
#define DVDCATEGORY_HPP

#include <string>

class DVDCategory {
    private:
        std::string _name;
        float _price;
    
    public:
        DVDCategory(std::string name, float price): _name(name), _price(price) {};

        std::string getName();
        float getPrice();
};

#endif