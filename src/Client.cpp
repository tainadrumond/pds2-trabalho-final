#include "../include/Client.hpp"
#include <string>

using namespace std;

string Client::getName()
{
    return _name;
}

string Client::getCpf()
{
    return _cpf;
}

void Client::setName(string name)
{
    _name = name;
}

void Client::setCpf(string cpf)
{
    bool cpfIsAuthentic = checkIfCpfIsAuthentic(cpf);
    if (!cpfIsAuthentic)
    {
        throw NonExistentCPF();
    }
    _cpf = cpf;
}

bool Client::checkIfCpfIsAuthentic(string cpf)
{
    std::string numericCpf;
    for (char ch : cpf)
    {
        if (std::isdigit(ch))
        {
            numericCpf.push_back(ch);
        }
    }

    if (numericCpf.length() != 11)
    {
        return false;
    }

    int firstVerifyingDigitSum = 0;
    for (int i = 0; i < 9; ++i)
    {
        firstVerifyingDigitSum += (numericCpf[i] - '0') * (10 - i);
    }
    int firstVerifyingDigitMod = firstVerifyingDigitSum % 11;
    int firstVerifyingDigit = (firstVerifyingDigitMod > 1) ? (11 - firstVerifyingDigitMod) : 0;

    if (firstVerifyingDigit != (numericCpf[9] - '0'))
    {
        return false;
    }

    int secondVerifyingDigitSum = 0;
    for (int i = 0; i < 10; ++i)
    {
        secondVerifyingDigitSum += (numericCpf[i] - '0') * (11 - i);
    }
    int secondVerifyingDigitMod = secondVerifyingDigitSum % 11;
    int secondVerifyingDigit = (secondVerifyingDigitMod > 1) ? (11 - secondVerifyingDigitMod) : 0;

    if (secondVerifyingDigit != (numericCpf[10] - '0'))
    {
        return false;
    }

    return true;
}
