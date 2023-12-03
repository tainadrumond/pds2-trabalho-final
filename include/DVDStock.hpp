#ifndef DVDStock_HPP
#define DVDStock_HPP

#include "Media.hpp"

class DVDStock : public Media
{
public:
    DVDStock(int id, std::string title, bool adult);
    ~DVDStock();

    float getRentPrice(int rentDays) override;
};

#endif