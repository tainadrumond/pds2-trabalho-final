#include "../include/Rent.hpp"
#include "../include/DVD.hpp"
#include <iostream>

using namespace std;

void Rent::printRentReceipt() {
    cout << "Cliente "  << _client->getCpf() << " " << _client->getName() << " alugou os filmes:" << endl;

    for(vector<Media*>::iterator media = _medias.begin(); media != _medias.end(); media++) {
         cout << (*media)->getId() << " " << (*media)->getTitle() << " ";
    }
}

void Rent::printDevolutionReceipt() {

}

Client* Rent::getClient() {
    return _client;
}

vector<Media*> Rent::getMedias() {
    return _medias;
}

float Rent::calculatePrice(int numberOfDays) {

}

float Rent::calculatePrice(int numberOfDays, Media* media) {

}

void Rent::printRentReport() {

}