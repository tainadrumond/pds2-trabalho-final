#ifndef STORE_HPP
#define STORE_HPP

#include "Client.hpp"
#include "Media.hpp"
#include "Rent.hpp"
#include "Extinguisher.hpp"
#include "DVDCategory.hpp"
#include <map>
#include <vector>

class Store
{
private:
    std::map<int, Client *> _clientsByCpf;
    std::map<int, Media *> _mediasById;
    std::map<int, Extinguisher> _ExtinguishersById;
    std::map<std::string, DVDCategory *> _dvdCategoriesByName;
    std::vector<Rent *> _rents;
    float _income;
    bool checkIfMediaHasActiveRents(int mediaId);

public:
    void setClient(Client *client);
    void setMedia(Media *media);
    void setRent(Rent *rent);
    void setDVDCategory(DVDCategory *dvdCategory);

    Client *getClient(int cpf);
    Media *getMedia(int id);
    Rent *getRent(int cpf);
    DVDCategory *getDVDCategory(string name);
    float getIncome();

    void removeMedia(int id);

    void calculateIncome();
};

#endif
