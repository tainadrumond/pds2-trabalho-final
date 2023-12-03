#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Rent.hpp"
#include "../include/Client.hpp"
#include "../include/VideoTape.hpp"
#include "../include/Media.hpp"
#include "../include/DVD.hpp"
#include "../include/DVDCategory.hpp"

#include <vector>

TEST_CASE("1: Testando construtor de Rent")
{
    Client client("Joao", 123456789);
    Media *media = new VideoTape("Titulo", 10, 1);
    vector<Media *> medias;
    medias.push_back(media);
    Rent rent(&client, medias);
    CHECK_EQ(rent.getClient(), &client);
}

TEST_CASE("2: Testando construtor de Rent")
{
    Client client("Joao", 123456789);
    Media *media = new VideoTape("Titulo", 10, 1);
    vector<Media *> medias;
    medias.push_back(media);
    Rent rent(&client, medias);
    CHECK_EQ(rent.getMedias().size(), 1);
}

TEST_CASE("3: Return rent")
{
    Client client("Joao", 123456789);
    Media *media = new VideoTape("Titulo", 10, 1);
    vector<Media *> medias;
    medias.push_back(media);
    Rent rent(&client, medias);
    rent.returnRent(1);
    CHECK_EQ(rent.isActive(), false);
}

TEST_CASE("4: Return rent")
{
    Client client("Joao", 123456789);
    DVDCategory category("Categoria", 10, true);
    Media *media = new DVD("Titulo", 10, 1, &category);
    vector<Media *> medias;
    medias.push_back(media);
    Rent rent(&client, medias);
    rent.returnRent(1);
    CHECK_EQ(rent.getPaymentAmount(), 10);
}
