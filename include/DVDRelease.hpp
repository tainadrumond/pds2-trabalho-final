#ifndef DVDRelease_HPP
#define DVDRelease_HPP

#include "Media.hpp"

class DVDRelease : public Media
{
public:
    DVDRelease(int id, std::string title, bool adult);
    ~DVDRelease();

    float getRentPrice(int rentDays) override;
};

#endif