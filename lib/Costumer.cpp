#include "../include/Costumer.hpp"

Costumer::Costumer(int cpf, std::string name, bool isAdult)
{
    _cpf = cpf;
    _name = name;
    _isAdult = isAdult;
}

Costumer::~Costumer()
{
}

int Costumer::getCpf()
{
    return _cpf;
}

std::string Costumer::getName()
{
    return _name;
}

void Costumer::setRent(Rent *rent)
{
    _rent = rent;
}

Rent *Costumer::getRent()
{
    return _rent;
}

bool Costumer::isAdult()
{
    return _isAdult;
}

bool Costumer::isAdult(bool isAdult)
{
    _isAdult = isAdult;
}