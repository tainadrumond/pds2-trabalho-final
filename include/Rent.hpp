#ifndef RENT_HPP
#define RENT_HPP

#include "Client.hpp"
#include "Media.hpp"
#include <vector>
#include <string>
#include <map>

using namespace std;

class Rent
{
private:
    Client *_client;
    vector<Media *> _medias;
    bool _active;
    float _paymentAmount;

    void printRentReceipt();
    void printDevolutionReceipt(map<int, float> pricesByMediaCode);

    // Returns the price for each media, mapped by code
    map<int, float> calculatePrice(int numberOfDays);

    // Returns the price of the media parameter
    float calculatePrice(int numberOfDays, Media *media);

public:
    Rent(Client *client, vector<Media *> medias) : _client(client), _medias(medias)
    {
        _active = true;
        printRentReceipt();
    };

    Client *getClient();
    vector<Media *> getMedias();
    float getPaymentAmount();
    bool isActive();

    void setMedias(vector<Media *> medias);

    void returnRent(int numberOfDays);
    void printRentReport();
};

#endif