#include "../include/Rent.hpp"
#include "../include/DVD.hpp"
#include "../include/VideoTape.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Client* Rent::getClient() {
    return _client;
}

vector<Media*> Rent::getMedias() {
    return _medias;
}

void Rent::printRentReceipt() {
    cout << "Cliente "  << _client->getCpf() << " " << _client->getName() << " alugou os filmes:" << endl;

    for(vector<Media*>::iterator media = _medias.begin(); media != _medias.end(); media++) {
         cout << (*media)->getId() << " " << (*media)->getTitle() << " " << (*media)->getMediaType() << endl;
    }
}

void Rent::printDevolutionReceipt(map<int, float> pricesByMediaCode) {
    cout << "Cliente "  << _client->getCpf() << " " << _client->getName() << " alugou os filmes:" << endl;

    for(vector<Media*>::iterator media = _medias.begin(); media != _medias.end(); media++) {
        int mediaId = (*media)->getId();
        cout << (*media)->getId() << " " << pricesByMediaCode.at(mediaId) << endl;
    }

    cout << "Total a pagar: " << _paymentAmount << endl;
}

map<int, float> Rent::calculatePrice(int numberOfDays) {
    map<int, float> priceByMediaCode;
    _paymentAmount = 0;

    for(vector<Media*>::iterator mediaIt = _medias.begin(); mediaIt != _medias.end(); mediaIt++) {
        float mediaPrice = calculatePrice(numberOfDays, (*mediaIt));
    
        pair<int, float> mapItem = pair<int, float>((*mediaIt)->getId(), mediaPrice);
        priceByMediaCode.insert(mapItem);

        _paymentAmount += mediaPrice;
    }

    return priceByMediaCode;
}

float Rent::calculatePrice(int numberOfDays, Media* media) {
    float paymentAmount = numberOfDays * media->getPrice();
    if (media->getMediaType() == "DVD") {
        return paymentAmount;
    }

    bool isTapeRewound = rand() % 2;
    VideoTape* videoTapePtr = dynamic_cast<VideoTape*>(media);

    float videoTapePaymentAmout = isTapeRewound && videoTapePtr != nullptr 
                                    ? paymentAmount + videoTapePtr->getPriceForRewoundDevolution()
                                    : paymentAmount;
    return videoTapePaymentAmout;
}

void Rent::returnRent(int numberOfDays) {
    map<int, float> pricesByMediaCode = calculatePrice(numberOfDays);
    printDevolutionReceipt(pricesByMediaCode);
    _active = false;
}

void Rent::printRentReport() {
    printRentReceipt();
}