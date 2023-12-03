#include "../include/Rent.hpp"
#include "../include/DVD.hpp"
#include "../include/VideoTape.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Client *Rent::getClient()
{
    return _client;
}

vector<Media *> Rent::getMedias()
{
    return _medias;
}

float Rent::getPaymentAmount()
{
    return _paymentAmount;
}

bool Rent::isActive()
{
    return _active;
}

void Rent::setMedias(vector<Media *> medias)
{
    vector<Media *>::iterator mediasEndIt = _medias.end();
    _medias.insert(mediasEndIt, medias.begin(), medias.end());
}

void Rent::printRentReceipt()
{
    cout << "Cliente " << _client->getCpf() << " " << _client->getName() << " alugou os filmes:" << endl;

    for (vector<Media *>::iterator media = _medias.begin(); media != _medias.end(); media++)
    {
        cout << (*media)->getId() << " " << (*media)->getTitle() << " " << (*media)->getMediaType() << endl;
    }
}

void Rent::printDevolutionReceipt(map<int, float> pricesByMediaCode)
{
    cout << "Cliente " << _client->getCpf() << " " << _client->getName() << " alugou os filmes:" << endl;

    for (vector<Media *>::iterator media = _medias.begin(); media != _medias.end(); media++)
    {
        int mediaId = (*media)->getId();
        cout << (*media)->getId() << " " << pricesByMediaCode.at(mediaId) << endl;
    }

    cout << "Total a pagar: " << _paymentAmount << endl;
}

map<int, float> Rent::calculatePrice(int numberOfDays)
{
    map<int, float> priceByMediaCode;
    _paymentAmount = 0;

    for (vector<Media *>::iterator mediaIt = _medias.begin(); mediaIt != _medias.end(); mediaIt++)
    {
        float mediaPrice = calculatePrice(numberOfDays, (*mediaIt));

        pair<int, float> mapItem = pair<int, float>((*mediaIt)->getId(), mediaPrice);
        priceByMediaCode.insert(mapItem);

        _paymentAmount += mediaPrice;
    }

    return priceByMediaCode;
}

float Rent::calculatePrice(int numberOfDays, Media *media)
{
    float paymentAmount = media->hasFixedPrice() ? media->getPrice() : numberOfDays * media->getPrice();
    if (media->getMediaType() == "DVD")
    {
        return paymentAmount;
    }

    bool isTapeRewound = rand() % 2;
    VideoTape *videoTapePtr = dynamic_cast<VideoTape *>(media);

    float videoTapePaymentAmout = isTapeRewound && videoTapePtr != nullptr
                                      ? paymentAmount + videoTapePtr->getPriceForRewoundDevolution()
                                      : paymentAmount;
    return videoTapePaymentAmout;
}

void Rent::returnRent(int numberOfDays)
{
    map<int, float> pricesByMediaCode = calculatePrice(numberOfDays);
    printDevolutionReceipt(pricesByMediaCode);
    _active = false;

    for (vector<Media *>::iterator mediaIt = _medias.begin(); mediaIt != _medias.end(); mediaIt++)
    {
        cout << "Por favor, avalie o filme " << (*mediaIt)->getTitle() << " com uma nota de 0 a 5: ";
        int rating;
        cin >> rating;
        (*mediaIt)->addRating(rating);
    }
    cout << "Obrigado por avaliar nossos filmes!" << endl;
}

void Rent::printRentReport()
{
    printRentReceipt();
}