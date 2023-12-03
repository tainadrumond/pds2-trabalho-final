#ifndef DBUTILS_HPP
#define DBUTILS_HPP

#include <string>
#include <vector>

#include "Media.hpp"
#include "Client.hpp"
#include "Rent.hpp"

class DbUtils
{
private:
    std::string _path;
    std::vector<Media> _media;
    std::vector<Client> _clients;
    std::vector<Rent> _rentals;

public:
    DbUtils(std::string path);

    void load();
    std::vector<Media *> get_media();
    std::vector<Client *> get_clients();
    std::vector<Rent *> get_rentals();

    void save(std::vector<Media> media, std::vector<Client> clients, std::vector<Rent> rentals);
};

#endif