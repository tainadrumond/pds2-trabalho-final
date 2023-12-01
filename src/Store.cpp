#include "Store.hpp"

using namespace std;

void Store::setClient(Client *client) {
    pair<int, Client*> clientPair = make_pair(client->getCpf(), client);
    _clientsByCpf.insert(clientPair);
}

void Store::setMedia(Media *media) {
    pair<int, Media*> mediaPair = make_pair(media->getId(), media);
    _mediasById.insert(mediaPair);
}

void Store::setRent(Rent* rent) {
    _rents.push_back(rent);
}

Client* Store::getClient(int cpf) {
    return _clientsByCpf.at(cpf);
}

Media* Store::getMedia(int id) {
    return _mediasById.at(id);
}

float Store::getIncome() {
    return _income;
}

Rent* Store::getRent(int cpf) {
    for(vector<Rent*>::iterator rentIt = _rents.begin(); rentIt != _rents.end(); rentIt++) {
        Client* rentClient = (*rentIt)->getClient();
        if (rentClient->getCpf() == cpf) {
            return *rentIt;
        }
    }
}

void Store::calculateIncome() {
    float totalIncome = 0.0;
    for(vector<Rent*>::iterator rentIt = _rents.begin(); rentIt != _rents.end(); rentIt++) {
        if ((*rentIt)->isActive()) {
            totalIncome += (*rentIt)->getPaymentAmount();
        }
    }
    _income = totalIncome;
}