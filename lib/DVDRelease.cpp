#include "../include/DVDRelease.hpp"

DVDRelease::DVDRelease(int id, std::string title, bool adult) : Media(id, title, adult)
{
}

DVDRelease::~DVDRelease()
{
}

float DVDRelease::getRentPrice(int rentDays)
{
    float price = 20 * rentDays;
}