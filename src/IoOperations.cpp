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
        cout << "ERRO: Dados incorretos. Entrada incoerente com o tipo esperado. Insira novamente" << endl;
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

    store->setMedia(media);
}

void removeMedia(Store *&store)
{
    int code;
    cin >> code;
    store->removeMedia(code);
}

void registerClient(Store *&store)
{
}
