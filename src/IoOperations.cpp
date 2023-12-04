#include "../include/IoOperations.hpp"
#include "../include/DVD.hpp"
#include "../include/VideoTape.hpp"
#include <iostream>
#include <climits>

template <typename T>
void read(T &input)
{
    cin.clear();

    while (!(cin >> input))
    {
        cout << "ERRO: dados incorretos. Entrada incoerente com o tipo esperado. Insira novamente" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void registerMedia(Store *&store)
{
    char type;
    int copies, code;
    string title;

    read(type);
    read(copies);
    read(code);
    read(title);

    Media *media;
    if (type == 'D')
    {
        string categoryName;
        read(categoryName);

        DVDCategory *dvdCategory = store->getDVDCategory(categoryName);

        if (dvdCategory == nullptr)
        {
            cout << "ERRO: dados incorretos. Categoria de DVD \"" << categoryName << "\" inexistente. Cadastro cancelado" << endl;
            return;
        }

        media = new DVD(title, copies, code, dvdCategory);
    }
    else if (type == 'F')
    {
        media = new VideoTape(title, copies, code);
    }
    else
    {
        cout << "ERRO: dados incorretos. Tipo de mídia " << type << " inexistente. Cadastro cancelado" << endl;
        return;
    }

    try
    {
        store->setMedia(media);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void removeMedia(Store *&store)
{
    int code;
    cin >> code;
    try
    {
        store->removeMedia(code);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void registerClient(Store *&store)
{
    string cpf;
    string name;
    read(cpf);
    read(name);

    Client *client;
    try
    {
        client = new Client(name, cpf);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << ". Cadastro cancelado" << endl;
        return;
    }

    try
    {
        store->setClient(client);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << ". Cadastro cancelado" << endl;
    }
}

void removeClient(Store *&store)
{
    string cpf;
    read(cpf);

    try
    {
        store->removeClient(cpf);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void listMedias(Store *&store)
{
    char orderBy;
    read(orderBy);
    try
    {
        store->listMedias(orderBy);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void listClients(Store *&store)
{
    char orderBy;
    read(orderBy);
    try
    {
        store->listClients(orderBy);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}
