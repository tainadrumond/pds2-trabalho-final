#define DOC_TEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Client.hpp"
#include "../include/VideoTape.hpp"
#include "../include/DVD.hpp"
#include "../include/DVDCategory.hpp"

#include <vector>

TEST_CASE("1: Testando construtor de Video Tape")
{
    VideoTape videoTape("Titulo", 10, 1);
    CHECK_EQ(videoTape.getId(), 1);
}

TEST_CASE("2: Testando construtor de Video Tape")
{
    VideoTape videoTape("Titulo", 10, 1);
    CHECK_EQ(videoTape.getTitle(), "Titulo");
}

TEST_CASE("3: Testando construtor de Video Tape")
{
    VideoTape videoTape("Titulo", 10, 1);
    CHECK_EQ(videoTape.getCopies(), 10);
}

TEST_CASE("4: Testando construtor de DVD")
{
    DVDCategory category("Categoria", 10, true);
    DVD dvd("Titulo", 10, 1, &category);
    CHECK_EQ(dvd.getMediaType(), "DVD");
}

TEST_CASE("5: Testando avaliacao de DVD")
{
    DVDCategory category("Categoria", 10, true);
    DVD dvd("Titulo", 10, 1, &category);
    dvd.addRating(5);
    CHECK_EQ(dvd.getRating(), 5);
}
