#ifndef IOOPERATIONS_HPP
#define IOOPERATIONS_HPP

#include "Store.hpp"
#include "DVDCategory.hpp"

template <typename T>
void read(T &input);

void registerMedia(Store *&store);

void removeMedia(Store *&store);

void registerClient(Store *&store);

#endif