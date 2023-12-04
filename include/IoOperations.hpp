#ifndef IOOPERATIONS_HPP
#define IOOPERATIONS_HPP

#include "Store.hpp"
#include "DVDCategory.hpp"

template <typename T>
void read(T &input);

void registerMedia(Store *&store);

void removeMedia(Store *&store);

void registerClient(Store *&store);

void removeClient(Store *&store);

void rent(Store *&store);

void returnRent(Store *&store);

void listMedias(Store *&store);

void listClients(Store *&store);

#endif