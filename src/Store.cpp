#include "Store.hpp"
#include <iostream>

using namespace std;

void Store::setClient(Client *client)
{
    auto clientIt = _clientsByCpf.find(client->getCpf());
    if (clientIt != _clientsByCpf.end())
    {
        throw invalid_argument("ERRO: CPF repetido");
    }
    pair<int, Client *> clientPair = make_pair(client->getCpf(), client);
    _clientsByCpf.insert(clientPair);
}

void Store::setMedia(Media *media)
{
    auto mediaIt = _mediasById.find(media->getId());
    if (mediaIt != _mediasById.end())
    {
        throw invalid_argument("ERRO: codigo repetido");
    }
    pair<int, Media *> mediaPair = make_pair(media->getId(), media);
    _mediasById.insert(mediaPair);

    cout << "Filme " << media->getId() << " cadastrado com sucesso" << endl;
}

void Store::setDVDCategory(DVDCategory *dvdCategory)
{
    auto categoryIt = _dvdCategoriesByName.find(dvdCategory->getName());
    if (categoryIt != _dvdCategoriesByName.end())
    {
        throw invalid_argument("Erro: categoria ja cadastrada");
    }
    pair<string, DVDCategory *> categoryPair = make_pair(dvdCategory->getName(), dvdCategory);
    _dvdCategoriesByName.insert(categoryPair);
}

void Store::setRent(Rent *rent)
{
    Client *client = rent->getClient();
    for (vector<Rent *>::iterator rentIt; rentIt != _rents.end(); rentIt++)
    {
        if ((*rentIt)->getClient()->getCpf() == client->getCpf())
        {
            cout << "Cliente " << client->getName() << " possui aluguel em andamento. ";
            cout << "Deseja incluir novos filmes? S/N ";
            char answer;
            cin >> answer;
            if (answer == 'S')
            {
                (*rentIt)->setMedias(rent->getMedias());
                (*rentIt)->printRentReport();
                break;
            }
            else
            {
                return;
            }
        }
    }
    _rents.push_back(rent);
}

Client *Store::getClient(int cpf)
{
    try
    {
        Client *client = _clientsByCpf.at(cpf);
        return client;
    }
    catch (out_of_range &e)
    {
        return nullptr;
    }
}

Media *Store::getMedia(int id)
{
    try
    {
        Media *media = _mediasById.at(id);
        return media;
    }
    catch (out_of_range &e)
    {
        return nullptr;
    }
}

DVDCategory *Store::getDVDCategory(string name)
{
    try
    {
        DVDCategory *dvdCategory = _dvdCategoriesByName.at(name);
        return dvdCategory;
    }
    catch (out_of_range &e)
    {
        return nullptr;
    }
}

float Store::getIncome()
{
    return _income;
}

Rent *Store::getRent(int cpf)
{
    for (vector<Rent *>::iterator rentIt = _rents.begin(); rentIt != _rents.end(); rentIt++)
    {
        Client *rentClient = (*rentIt)->getClient();
        if (rentClient->getCpf() == cpf)
        {
            return *rentIt;
        }
    }
    return nullptr;
}

bool Store::checkIfMediaHasActiveRents(int mediaId)
{
    for (vector<Rent *>::iterator rentIt = _rents.begin(); rentIt != _rents.end(); rentIt++)
    {
        if (!(*rentIt)->isActive())
        {
            continue;
        }

        vector<Media *> rentMedias = (*rentIt)->getMedias();
        for (vector<Media *>::iterator mediaIt = rentMedias.begin(); mediaIt != rentMedias.end(); mediaIt++)
        {
            if ((*mediaIt)->getId() == mediaId)
            {
                return true;
            }
        }
    }
    return false;
}

void Store::removeMedia(int id)
{
    auto mediaIt = _mediasById.find(id);
    if (mediaIt == _mediasById.end())
    {
        throw invalid_argument("ERRO: codigo inexistente");
    }

    bool mediaHasActiveRents = checkIfMediaHasActiveRents(id);
    if (mediaHasActiveRents)
    {
        throw invalid_argument("ERRO: o filme nao pode ser removido pois possui alugueis ativos");
    }

    _mediasById.erase(mediaIt);
    cout << "Filme " << id << " removido com sucesso" << endl;
}

void Store::calculateIncome()
{
    float totalIncome = 0.0;
    for (vector<Rent *>::iterator rentIt = _rents.begin(); rentIt != _rents.end(); rentIt++)
    {
        if ((*rentIt)->isActive())
        {
            totalIncome += (*rentIt)->getPaymentAmount();
        }
    }
    _income = totalIncome;
}