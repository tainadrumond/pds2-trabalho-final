#include <fstream>
#include <iostream>
#include <sstream>
#include "../include/DbUtils.hpp"

DbUtils::DbUtils(std::string path) : _path(path){};

void DbUtils::save(std::vector<Media> media, std::vector<Client> clients, std::vector<Rent> rentals)
{
    std::ofstream file;
    file.open(_path);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    for (std::vector<Media>::iterator it = media.begin(); it != media.end(); it++)
    {
        file << "M"
             << " " << it->getId() << " " << it->getTitle() << " " << it->getPrice() << " " << it->getCopies() << std::endl;
    }

    for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        file << "C"
             << " " << it->getCpf() << " " << it->getName() << std::endl;
    }

    for (std::vector<Rent>::iterator it = rentals.begin(); it != rentals.end(); it++)
    {
        file << "R"
             << " " << it->getClient()->getCpf() << " " << it->getMedias().size() << " ";
        for (std::vector<Media *>::iterator it2 = it->getMedias().begin(); it2 != it->getMedias().end(); it2++)
        {
            file << (*it2)->getId() << " ";
        }
        file << std::endl;
    }

    file.close();
}

void DbUtils::load()
{
    std::ifstream file;
    file.open(_path);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "M")
        {
            int id;
            std::string title;
            float price;
            int copies;
            iss >> id >> title >> price >> copies;
            Media media(id, title, copies, price);
            _media.push_back(media);
        }
        else if (type == "C")
        {
            int cpf;
            std::string name;
            iss >> cpf >> name;
            Client client(name, cpf);
            _clients.push_back(client);
        }
        else if (type == "R")
        {
            int cpf;
            int numberOfMedias;
            iss >> cpf >> numberOfMedias;
            std::vector<Media *> medias;
            for (int i = 0; i < numberOfMedias; i++)
            {
                int id;
                iss >> id;
                for (std::vector<Media>::iterator it = _media.begin(); it != _media.end(); it++)
                {
                    if (it->getId() == id)
                    {
                        medias.push_back(&(*it));
                    }
                }
            }
            for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++)
            {
                if (it->getCpf() == cpf)
                {
                    Rent rent(&(*it), medias);
                    _rentals.push_back(rent);
                }
            }
        }
    }

    file.close();
}

std::vector<Media> DbUtils::get_media()
{
    return _media;
}

std::vector<Client> DbUtils::get_clients()
{
    return _clients;
}

std::vector<Rent> DbUtils::get_rentals()
{
    return _rentals;
}