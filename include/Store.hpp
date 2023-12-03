#ifndef STORE_HPP
#define STORE_HPP

#include "Stock.hpp"
#include "Costumer.hpp"
#include "Rent.hpp"
#include "Media.hpp"

#include <vector>

class Store
{
private:
    Stock _stock;
    std::vector<Costumer *> _costumers;
    std::vector<Rent *> _rents;
    std::vector<Media *> _medias;

public:
    Store();
    ~Store();

    void addCostumer(Costumer *costumer);
    void removeCostumer(int cpf);

    void addMedia(Media *media);
    void removeMedia(int id);

    void addRent(Rent *rent);

    void setStock(int id, int stock);
    int getStock(int id);

    Costumer *getCostumer(int cpf);
    Media *getMedia(int id);

    void rentMedia(int idCostumer, std::vector<int> idMedia);
    void giveBackMedia(int idCostumer);

    void giveSuggestion();
};

#endif