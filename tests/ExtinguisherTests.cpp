#define DOC_TEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Extinguisher.hpp"

TEST_CASE("1: Testando construtor de Extinguisher")
{
    Extinguisher extinguisher(10, true);
    CHECK_EQ(extinguisher.getDaysToExpDate(), 10);
}

TEST_CASE("2: Testando Refuel")
{
    Extinguisher extinguisher(10, true);
    extinguisher.refuel();
    CHECK_EQ(extinguisher.getDaysToExpDate(), 20);
}

TEST_CASE("3: Testando GetDaysToExpDate")
{
    Extinguisher extinguisher(10, true);
    CHECK_EQ(extinguisher.getDaysToExpDate(), 10);
}