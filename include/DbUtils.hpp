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
  /**
 * @brief Construtor do DbUtils.
 */
    DbUtils(std::string path);
  /**
 * @brief Método que carrega um arquivo de acordo com o caminho já informado.
 */
    void load();
  /**
 * @brief Método que pega um vetor de mídias.
 * 
 * @return Vetor de mídias.
 */
    std::vector<Media *> get_media();
  /**
 * @brief Método que pega um vetor de clientes.
 * 
 * @return Vetor de clientes.
 */
    std::vector<Client *> get_clients();
  /**
 * @brief Método que pega um vetor de aluguéis.
 * 
 * @return Vetor de aluguéis.
 */
    std::vector<Rent *> get_rentals();
  /**
 * @brief Método que salva todas as informações.
 */
    void save(std::vector<Media> media, std::vector<Client> clients, std::vector<Rent> rentals);
};

#endif