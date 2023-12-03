#ifndef COSTUMER_HPP
#define COSTUMER_HPP

#include "Rent.hpp"

#include <string>

class Costumer
{
private:
    int _cpf;
    std::string _name;
    Rent *_rent;
    bool _isAdult;

public:
    Costumer(int cpf, std::string name, bool isAdult);
    ~Costumer();

    int getCpf();
    std::string getName();

    void setRent(Rent *rent);
    Rent *getRent();

    bool isAdult();
    bool isAdult(bool isAdult);
};

#endif
