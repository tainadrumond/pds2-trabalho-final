#include "../include/Client.hpp"
#include <string>

std::string Client::getName() {
    return _name;
}

int Client::getCpf() {
    return _cpf;
}

void Client::setName(std::string name) {
    _name = name;
}

void Client::setCpf(int cpf) {
    _cpf = cpf;
}

