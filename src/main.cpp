#include "../include/DVD.hpp"
#include "../include/VideoTape.hpp"
#include "../include/Store.hpp"
#include "../include/IoOperations.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void initDefaultDVDCategories(Store *&store)
{
  store->setDVDCategory(new DVDCategory("Lancamento", 20, false));
  store->setDVDCategory(new DVDCategory("Estoque", 10, false));
  store->setDVDCategory(new DVDCategory("Promocao", 10, true));
}

int main()
{
  Store *store = new Store();
  initDefaultDVDCategories(store);

  map<string, int> const commands = {
      {"LA", 1},
      {"CF", 2},
      {"RF", 3},
      {"LF", 4},
      {"CC", 5},
      {"RC", 6},
      {"LC", 7},
      {"AL", 8},
      {"DV", 9},
      {"FS", 10}};

  string textIn;

  while (true)
  {
    read(textIn);

    auto it = commands.find(textIn); // Se o comando de entrada tiver dentro do map, então entra no switch case
    if (it != commands.end())
    {
      int numberIn = it->second;

      switch (numberIn)
      {
      case 1: // "LA"
        break;

      case 2: // "CF"
        registerMedia(store);
        break;

      case 3: // "RF"
        removeMedia(store);
        break;

      case 4: // "LF"
        listMedias(store);
        break;

      case 5: // "CC"
        registerClient(store);
        break;

      case 6: // "RC"
        removeClient(store);
        break;

      case 7: // "LC"
        listClients(store);
        break;

      case 8: // "AL"
        rent(store);
        break;

      case 9: // "DV"
        returnRent(store);
        break;

      case 10: //"FS"
        return (0);
        break;

      default:
        cout << "ERRO" << endl;
        break;
      }
    }
    else
    {
      cout << "ERRO: comando inválido. Comandos disponíveis: CF, RF, LF, CC, RC, LC, AL, DV, FS" << endl;
    }
  }

  return 0;
}
