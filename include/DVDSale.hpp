#ifndef DVD_SALE_HPP
#define DVD_SALE_HPP

#include "Media.hpp"

class DVDSale : public Media
{
public:
    DVDSale(int id, std::string title, bool adult);
    ~DVDSale();

    float getRentPrice(int rentDays) override;
};

#endif