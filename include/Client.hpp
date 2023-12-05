#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Exceptions.hpp"
#include <string>
#include <iostream>

using namespace std;

class Client
{
private:
  string _name;
  string _cpf;
  bool checkIfCpfIsAuthentic(string cpf);
  /**
   * @brief Método que checa se o CPF é autêntico.
   *
   * @return Booleano de autenticidade do CPF.
   */
public:
  /**
   * @brief Método que constrói o cliente.
   */
  Client(string name, string cpf) : _name(name)
  {
    bool cpfIsAuthentic = checkIfCpfIsAuthentic(cpf);
    if (!cpfIsAuthentic)
    {
      throw NonExistentCPF();
    }
    _cpf = cpf;
  };
  /**
   * @brief Método que informa o nome do cliente.
   *
   * @return Nome do cliente.
   */
  string getName();
  /**
   * @brief Método que informa o CPF do cliente.
   *
   * @return CPF do cliente.
   */
  string getCpf();
  /**
   * @brief Método que determina o nome do cliente.
   */
  void setName(string name);
  /**
   * @brief Método que determina o CPF do cliente.
   */
  void setCpf(string cpf);
};

#endif