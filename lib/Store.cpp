#include "../include/Store.hpp"

#include <iostream>
#include <algorithm>

Store::Store()
{
}

Store::~Store()
{
}

void Store::addMedia(Media *media)
{
    _medias.push_back(media);
}

void Store::removeMedia(int id)
{
    for (int i = 0; i < _medias.size(); i++)
    {
        if (_medias[i]->getId() == id)
        {
            _medias.erase(_medias.begin() + i);
            break;
        }
    }
}

void Store::addCostumer(Costumer *costumer)
{
    _costumers.push_back(costumer);
}

void Store::removeCostumer(int cpf)
{
    for (int i = 0; i < _costumers.size(); i++)
    {
        if (_costumers[i]->getCpf() == cpf)
        {
            _costumers.erase(_costumers.begin() + i);
            break;
        }
    }
}

void Store::addRent(Rent *rent)
{
    _rents.push_back(rent);
}

Costumer *Store::getCostumer(int cpf)
{
    for (int i = 0; i < _costumers.size(); i++)
    {
        if (_costumers[i]->getCpf() == cpf)
        {
            return _costumers[i];
        }
    }
    return NULL;
}

Media *Store::getMedia(int id)
{
    for (int i = 0; i < _medias.size(); i++)
    {
        if (_medias[i]->getId() == id)
        {
            return _medias[i];
        }
    }
    return NULL;
}

void Store::rentMedia(int cpf, std::vector<int> idMedia)
{
    Costumer *costumer = getCostumer(cpf);
    if (costumer == NULL)
    {
        std::cout << "Costumer not found" << std::endl;
        return;
    }

    for (int i = 0; i < idMedia.size(); i++)
    {
        Media *media = getMedia(idMedia[i]);
        if (media == NULL)
        {
            std::cout << "Media not found" << std::endl;
            return;
        }

        if (!costumer->isAdult() && media->isAdult())
        {
            std::cout << "A non adult client can't rent an adults only media" << std::endl;
            return;
        }

        if (_stock.getStock(idMedia[i]) == 0)
        {
            std::cout << "Media out of stock" << std::endl;
            return;
        }

        _stock.decrement(idMedia[i]);
    }

    Rent *rent = new Rent(cpf, idMedia);
    costumer->setRent(rent);
    addRent(rent);
}

void Store::giveSuggestion()
{
    std::vector<Media *> medias = _medias;
    std::sort(medias.begin(), medias.end(), [](Media *a, Media *b)
              { return a->getRating() > b->getRating(); });

    std::cout << "New renting suggestions: " << medias[0]->getTitle() << ", " << medias[1]->getTitle() << " and " << medias[2]->getTitle() << std::endl;
}

void Store::giveBackMedia(int cpf)
{
    Costumer *costumer = getCostumer(cpf);
    if (costumer == NULL)
    {
        std::cout << "Costumer not found" << std::endl;
        return;
    }

    Rent *rent = costumer->getRent();
    if (rent == NULL)
    {
        std::cout << "Costumer has no rent" << std::endl;
        return;
    }

    rent->close();
    std::cout << "Rent closed" << std::endl;

    float total = 0;
    for (int i = 0; i < rent->getIdMedia().size(); i++)
    {
        _stock.increment(rent->getIdMedia()[i]);

        Media *media = getMedia(rent->getIdMedia()[i]);
        total += media->getRentPrice(rent->getDays());

        std::cout << "Please rate media: " << media->getTitle() << ", in a scale of 1 to 10." << std::endl;
        int rating;
        std::cin >> rating;
        media->addRating(rating);
    }

    std::cout << "Total: " << total << std::endl;
    giveSuggestion();
}