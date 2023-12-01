#ifndef RENT_HPP
#define RENT_HPP

#include "Client.hpp"
#include "Media.hpp"
#include <vector>
#include <string>
#include <map>

class Rent {
    private:
        Client* _client;
        std::vector<Media*> _medias;
        bool _active;
        float _paymentAmount;

        void printRentReceipt();
        void printDevolutionReceipt(std::map<int, float> pricesByMediaCode);

        // Returns the price for each media, mapped by code
        std::map<int, float> calculatePrice(int numberOfDays);

        // Returns the price of the media parameter
        float calculatePrice(int numberOfDays, Media* media);

    public:
        Rent(Client* client, std::vector<Media*> medias): _client(client), _medias(medias) {
            _active = true;
            printRentReceipt();
        };

        Client* getClient();
        std::vector<Media*> getMedias();
        float getPaymentAmount();
        bool isActive();

        void returnRent(int numberOfDays);
        void printRentReport();
};

#endif