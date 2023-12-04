#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Client.hpp"

TEST_CASE("1: Testando construtor de Client")
{
    Client client("Joao", 123456789);
    CHECK_EQ(client.getName(), "Joao");
}

TEST_CASE("2: Testando construtor de Client")
{
    Client client("Joao", 123456789);
    CHECK_EQ(client.getCpf(), 123456789);
}

TEST_CASE("3: Testando alteracao de nome")
{
    Client client("Joao", 123456789);
    client.setName("Maria");
    CHECK_EQ(client.getName(), "Maria");
}