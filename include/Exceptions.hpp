#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

using namespace std;

class NonExistentFile : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "ERRO: arquivo inexistente";
    }
};

class IncorrectData : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "ERRO: dados incorretos";
    }
};

class RepeatedCode : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "ERRO: codigo repetido";
    }
};

class NonExistentCode : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "ERRO: codigo inexistente";
    }
};

class RepeatedCPF : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "ERRO: CPF repetido";
    }
};

class NonExistentCPF : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "ERRO: CPF inexistente";
    }
};

class NonExistentMedia : public exception
{
private:
    string _errorMessage;

public:
    NonExistentMedia(string mediaCode) : _errorMessage("ERRO: Filme " + mediaCode + " inexistente") {}
    virtual const char *what() const throw()
    {
        return _errorMessage.c_str();
    }
};

#endif