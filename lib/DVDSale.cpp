#include "../include/DVDSale.hpp"

DVDSale::DVDSale(int id, std::string title, bool adult) : Media(id, title, adult)
{
}

DVDSale::~DVDSale()
{
}

float DVDSale::getRentPrice(int rentDays)
{
    float price = 10;
}