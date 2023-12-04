#ifndef STORE_HPP
#define STORE_HPP

#include "Client.hpp"
#include "Media.hpp"
#include "Rent.hpp"
#include "Extinguisher.hpp"
#include "DVDCategory.hpp"
#include <map>
#include <vector>

class Store
{
private:
   /**
    * @brief Mapa de Clientes e CPFs.
    */
   std::map<string, Client *> _clientsByCpf;
   std::map<int, Media *> _mediasById;
   std::map<int, Extinguisher> _ExtinguishersById;
   std::map<std::string, DVDCategory *> _dvdCategoriesByName;
   std::vector<Rent *> _rents;
   float _income;
   bool checkIfMediaHasActiveRents(int mediaId);
   /**
    * @brief Método que checa o estado de aluguéis de uma mídia.
    *
    * Retorna valores booleanos para mostrar o estado de aluguéis de uma mídia.
    *
    * @return Booleano indicador de presença ou ausência de aluguéis.
    */

public:
   /**
    * @brief Método que adiciona um cliente à locadora.
    */
   void setClient(Client *client);
   /**
    * @brief Método que adiciona uma mídia à locadora.
    */
   void setMedia(Media *media);
   /**
    * @brief Método que adiciona informações de um aluguel à locadora.
    */
   void setRent(Rent *rent);
   /**
    * @brief Método que determina a categoria de um DVD.
    */
   void setDVDCategory(DVDCategory *dvdCategory);

   /**
    * @brief Método que informa um cliente de acorod com CPF.
    *
    * Retorna um cliente buscado pelo seu CPF
    *
    * @return Cliente.
    */
   Client *getClient(string cpf);
   /**
    * @brief Método que informa uma mídia de acordo com seu número de ID.
    *
    * Retorna uma mídia buscada pelo seu ID.
    *
    * @return Mídia.
    */
   Media *getMedia(int id);
   /**
    * @brief Método que dá informações de aluguel de acordo com o número de CPF do cliente.
    *
    * Retorna um aluguel buscado pelo CPF.
    *
    * @return Aluguel.
    */
   Rent *getRent(string cpf);
   /**
    * @brief Método que dá informações de uma categoria de DVD de acordo com o nome do filme.
    *
    * Retorna uma categoria de DVD buscada pelo nome.
    *
    * @return Categoria de DVD.
    */
   DVDCategory *getDVDCategory(string name);
   /**
    * @brief Método que dá informações do total dos valores do aluguel.
    *
    * Retorna um Σ dos valores de cada aluguel.
    *
    * @return Float.
    */
   float getIncome();
   /**
    * @brief Método que remove uma mídia de acordo com o seu número de ID.
    *
    * Remove mídia buscada por ID
    */
   void removeMedia(int id);
   /**
    * @brief Método que calcula o total dos valores do aluguel.
    *
    * Calcula um Σ dos valores de cada aluguel.
    */
   void calculateIncome();
   /**
    * @brief Método que determina sugestões de filmes de acordo com avaliações passadas.
    */
   void giveSuggestion();
   /**
    * @brief Método que remove um cliente de acordo com o núemro do CPF.
    */
   void removeClient(string cpf);
   /**
    * @brief Método que imprime todos os filmes, ordenados por código, para o parâmetro 'C', ou título, para o parâmetro 'T'.
    */
   void listMedias(char orderBy);
   /**
    * @brief Método que imprime todos os clientes, ordenados por CPF, para o parâmetro 'C', ou nome, para o parâmetro, 'N'.
    */
   void listClients(char orderBy);
};

#endif
