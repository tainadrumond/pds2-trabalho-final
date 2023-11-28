#ifndef RENT_HPP
#define RENT_HPP

#include "Client.hpp"
#include "Media.hpp"
#include <vector>
#include <string>

class Rent {
    private:
        Client* _client;
        std::vector<Media*> _medias;

        void printRentReceipt();
        void printDevolutionReceipt();

    public:
        Rent(Client* client, std::vector<Media*> medias): _client(client), _medias(medias) {
            for (std::vector<Media*>::iterator it = medias.begin(); it != medias.end(); it++) {
                (*it)->rent();
            }
            printRentReceipt();
        };

        ~Rent() {
            printDevolutionReceipt();
        }

        Client* getClient();
        std::vector<Media*> getMedias();

        // Returns the total price
        float calculatePrice(int numberOfDays);

        // Returns the price of the media parameter
        float calculatePrice(int numberOfDays, Media* media);

        void printRentReport();
};

#endif