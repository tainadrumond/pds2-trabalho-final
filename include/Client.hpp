#include <string>

using namespace std;

#ifndef CLIENT_H
#define CLIENT_H

class Client {
    private:
        string name;
        int cpf;

    public:
        Client(string name, int cpf): name(name), cpf(cpf) {};
        void setName(string name);
        string getName();
        void setCpf(int cpf);
        int getCpf();
};

#endif