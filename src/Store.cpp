#include "../include/Store.hpp"
#include "../include/Exceptions.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void Store::setClient(Client *client)
{
    auto clientIt = _clientsByCpf.find(client->getCpf());
    if (clientIt != _clientsByCpf.end())
    {
        throw NonExistentCPF();
    }
    pair<string, Client *> clientPair = make_pair(client->getCpf(), client);
    _clientsByCpf.insert(clientPair);

    cout << "Cliente " << client->getCpf() << " cadastrado com sucesso" << endl;
}

void Store::setMedia(Media *media)
{
    auto mediaIt = _mediasById.find(media->getId());
    if (mediaIt != _mediasById.end())
    {
        throw RepeatedCode();
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
        throw invalid_argument("ERRO: categoria ja cadastrada");
    }
    pair<string, DVDCategory *> categoryPair = make_pair(dvdCategory->getName(), dvdCategory);
    _dvdCategoriesByName.insert(categoryPair);
}

void Store::setRent(Rent *rent)
{
    Client *client = rent->getClient();
    for (vector<Rent *>::iterator rentIt = _rents.begin(); rentIt != _rents.end(); rentIt++)
    {
        if ((*rentIt)->getClient()->getCpf() == client->getCpf())
        {
            throw invalid_argument("ERRO: cliente " + client->getName() + " possui aluguel em andamento. ");
        }
    }

    vector<Media *> medias = rent->getMedias();
    if (medias.size() == 0)
    {
        throw invalid_argument("ERRO: é necessário inserir os filmes que serao alugados.");
    }

    _rents.push_back(rent);
    rent->printRentReceipt();
}

Client *Store::getClient(string cpf)
{
    try
    {
        Client *client = _clientsByCpf.at(cpf);
        return client;
    }
    catch (out_of_range &e)
    {
        throw NonExistentCPF();
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
        throw NonExistentMedia(to_string(id));
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

Rent *Store::getRent(string cpf)
{
    for (vector<Rent *>::iterator rentIt = _rents.begin(); rentIt != _rents.end(); rentIt++)
    {
        if (!(*rentIt)->isActive())
        {
            continue;
        }
        Client *rentClient = (*rentIt)->getClient();
        if (rentClient->getCpf() == cpf)
        {
            return *rentIt;
        }
    }
    throw NonExistentCPF();
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
        throw NonExistentCode();
    }

    bool mediaHasActiveRents = checkIfMediaHasActiveRents(id);
    if (mediaHasActiveRents)
    {
        throw invalid_argument("ERRO: o filme nao pode ser removido pois possui alugueis ativos");
    }

    _mediasById.erase(mediaIt);
    cout << "Filme " << id << " removido com sucesso" << endl;
}

void Store::removeClient(string cpf)
{
    auto clientIt = _clientsByCpf.find(cpf);
    if (clientIt == _clientsByCpf.end())
    {
        throw NonExistentCPF();
    }

    try
    {
        Rent *rent = getRent(cpf);
        if (rent != nullptr)
        {
            throw invalid_argument("ERRO: o cliente não pode ser removido pois possui alugueis ativos");
        }
    }
    catch (invalid_argument &e)
    {
        _clientsByCpf.erase(clientIt);
        cout << "Cliente " << cpf << " removido com sucesso" << endl;
    }
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

void Store::giveSuggestion()
{
    vector<pair<int, Media *>> sortedMediasByRating(_mediasById.begin(), _mediasById.end());
    sort(sortedMediasByRating.begin(), sortedMediasByRating.end(), [](pair<int, Media *> a, pair<int, Media *> b)
         { return a.second->getRating() > b.second->getRating(); });

    cout << "Sugestão de mídias:" << endl;
    for (int i = 0; i < sortedMediasByRating.size(); i++)
    {
        if (i == 3)
        {
            break;
        }
        cout << i + 1 << " - " << sortedMediasByRating[i].second->getTitle() << endl;
    }
}

void Store::listMedias(char orderBy)
{
    vector<pair<int, Media *>> medias(_mediasById.begin(), _mediasById.end());
    if (orderBy == 'C')
    {
        sort(medias.begin(), medias.end(), [](const auto &a, const auto &b)
             { return a.first < b.first; });
    }
    else if (orderBy == 'T')
    {
        sort(medias.begin(), medias.end(), [](const auto &a, const auto &b)
             { return (a.second)->getTitle() < (b.second)->getTitle(); });
    }
    else
    {
        throw invalid_argument("ERRO: dados incorretos. Opção de ordenamento " + to_string(orderBy) + " inválida.");
    }

    Media *tempMedia;
    for (vector<pair<int, Media *>>::iterator mediaIt = medias.begin(); mediaIt != medias.end(); mediaIt++)
    {
        tempMedia = (*mediaIt).second;
        cout << tempMedia->getId() << " " << tempMedia->getTitle() << " ";
        cout << tempMedia->getCopies() << " " << tempMedia->getMediaType() << endl;
    }
}

void Store::listClients(char orderBy)
{
    vector<pair<string, Client *>> clients(_clientsByCpf.begin(), _clientsByCpf.end());
    if (orderBy == 'C')
    {
        sort(clients.begin(), clients.end(), [](const auto &a, const auto &b)
             { return a.first < b.first; });
    }
    else if (orderBy == 'N')
    {
        sort(clients.begin(), clients.end(), [](const auto &a, const auto &b)
             { return (a.second)->getName() < (b.second)->getName(); });
    }
    else
    {
        throw invalid_argument("ERRO: dados incorretos. Opção de ordenamento " + to_string(orderBy) + " inválida.");
    }

    Client *tempClient;
    for (vector<pair<string, Client *>>::iterator clientIt = clients.begin(); clientIt != clients.end(); clientIt++)
    {
        tempClient = (*clientIt).second;
        cout << tempClient->getCpf() << " " << tempClient->getName() << endl;
    }
}