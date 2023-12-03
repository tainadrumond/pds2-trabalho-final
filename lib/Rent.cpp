#include "Rent.hpp"

Rent::Rent(int idCostumer, std::vector<int> idMedia)
{
    _idCostumer = idCostumer;
    _idMedia = idMedia;
    _rentDate = std::chrono::system_clock::now();
}

Rent::~Rent()
{
}

int Rent::getIdCostumer()
{
    return _idCostumer;
}

std::vector<int> Rent::getIdMedia()
{
    return _idMedia;
}

void Rent::close()
{
    _giveBackDate = std::chrono::system_clock::now();
    _isClosed = true;
}

bool Rent::isClosed()
{
    return _isClosed;
}

int Rent::getDays()
{
    std::chrono::duration<double> days = _giveBackDate - _rentDate;
    return days.count();
}