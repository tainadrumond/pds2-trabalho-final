#ifndef IOOPERATIONS_HPP
#define IOOPERATIONS_HPP

#include "Store.hpp"
#include "DVDCategory.hpp"

 /**
 * @brief Método que lê um valor de um tipo específico.
 */
template <typename T>
void read(T &input);
 /**
 * @brief Método que adiciona uma mídia.
 */
void registerMedia(Store *&store);
 /**
 * @brief Método que remove uma mídia.
 */
void removeMedia(Store *&store);
 /**
 * @brief Método que adiciona um cliente.
 */
void registerClient(Store *&store);
 /**
 * @brief Método que remove um cliente.
 */
void removeClient(Store *&store);

void rent(Store *&store);

void returnRent(Store *&store);

void listMedias(Store *&store);

void listClients(Store *&store);

#endif