#include "../include/DVDStock.hpp"

DVDStock::DVDStock(int id, std::string title, bool adult) : Media(id, title, adult)
{
}

DVDStock::~DVDStock()
{
}

float DVDStock::getRentPrice(int rentDays)
{
    float price = 10 * rentDays;
}