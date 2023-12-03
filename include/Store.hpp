#ifndef STORE_HPP
#define STORE_HPP

#include "Client.hpp"
#include "Media.hpp"
#include "Rent.hpp"
#include "Extinguisher.hpp"
#include <map>
#include <vector>

class Store
{
private:
    std::map<int, Client *> _clientsByCpf;
    std::map<int, Media *> _mediasById;
    std::map<int, Extinguisher> _ExtinguishersById;
    std::vector<Rent *> _rents;
    float income;

public:
    void setClient(Client *client);
    void setMedia(Media *media);
    void setRent(Rent *rent);

    Client *getClient(int cpf);
    Media *getMedia(int id);
    Rent *getRent(int cpf);
    float getIncome();

    void calculateIncome();
};

#endif
