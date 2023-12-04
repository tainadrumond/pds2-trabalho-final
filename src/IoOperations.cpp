#include "../include/IoOperations.hpp"
#include "../include/DVD.hpp"
#include "../include/VideoTape.hpp"
#include "../include/DbUtils.hpp"
#include <iostream>
#include <climits>

template <typename T>
void read(T &input)
{
    cin.clear();

    if (!(cin >> input))
    {
        throw invalid_argument("ERRO: Dados incorretos. Entrada incoerente com o tipo esperado. Operação cancelada");
    }
}

void registerMedia(Store *&store)
{
    char type;
    int copies, code;
    string title;

    try
    {
        read(type);
        read(copies);
        read(code);
        read(title);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }

    Media *media;
    if (type == 'D')
    {
        string categoryName;

        try
        {
            read(categoryName);
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }

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

    try
    {
        read(cpf);
        read(name);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }

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

    try
    {
        read(cpf);
        store->removeClient(cpf);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void rent(Store *&store)
{
    string cpf;
    vector<int> mediaIds = {};

    Client *client;
    try
    {
        read(cpf);
        client = store->getClient(cpf);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }

    cout << "Digite -1 quando terminar de inserir os filmes a serem alocados" << endl;

    int tempMediaId;
    while (cin >> tempMediaId)
    {
        if (tempMediaId == -1)
        {
            break;
        }
        mediaIds.push_back(tempMediaId);
    }

    vector<Media *> medias;
    Media *tempMedia;
    for (vector<int>::iterator mediaIdIt = mediaIds.begin(); mediaIdIt != mediaIds.end(); mediaIdIt++)
    {
        try
        {
            tempMedia = store->getMedia(*mediaIdIt);
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            return;
        }
        medias.push_back(tempMedia);
    }

    try
    {
        Rent *rent = new Rent(client, medias);
        store->setRent(rent);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }
}

void returnRent(Store *&store)
{
    string cpf;
    int numberOfDays;

    Rent *rent;
    try
    {
        read(cpf);
        read(numberOfDays);
        rent = store->getRent(cpf);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        return;
    }

    rent->returnRent(numberOfDays);
    store->giveSuggestion();
}

void listMedias(Store *&store)
{
    char orderBy;
    try
    {
        read(orderBy);
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
    try
    {
        read(orderBy);
        store->listClients(orderBy);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void readFile()
{
    string path;
    read(path);
    DbUtils DbUtils(path);
    DbUtils.load();    
}