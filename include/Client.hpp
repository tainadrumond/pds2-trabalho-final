#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>

using namespace std;

class Client
{
private:
    string _name;
    string _cpf;
    bool checkIfCpfIsAuthentic(string cpf);

public:
    Client(string name, string cpf) : _name(name)
    {
        bool cpfIsAuthentic = checkIfCpfIsAuthentic(cpf);
        if (!cpfIsAuthentic)
        {
            throw invalid_argument("ERRO: CPF inválido");
        }
        _cpf = cpf;
    };

    string getName();
    string getCpf();

    void setName(string name);
    void setCpf(string cpf);
};

#endif