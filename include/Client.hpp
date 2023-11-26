#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {
    private:
        std::string _name;
        int _cpf;

    public:
        Client(std::string name, int cpf): _name(name), _cpf(cpf) {};

        std::string getName();
        int getCpf();
        
        void setName(std::string name);
        void setCpf(int cpf);
};

#endif