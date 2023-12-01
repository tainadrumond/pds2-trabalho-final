#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{

  map<string, int> commands = {
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
    cin >> textIn;

    auto it = commands.find(textIn); //Se o comando de entrada tiver dentro do map, então entra no switch case
    if (it != commands.end()){
      int numberIn = it->second;

      switch (numberIn)
      {
      case 1: // "LA"
        break;

      case 2: // "CF"
        break;

      case 3: // "RF"
        break;

      case 4: // "LF"
        break;

      case 5: // "CC"
        break;

      case 6: // "RC"
        break;

      case 7: // "LC"
        break;

      case 8: // "AL"
        break;

      case 9: // "DV"
        break;

      case 10: //"FS"
      return(0);
        break;

      default:
        cout << "ERRO" << endl;
        break;
      }
    }
    else{
      cout << "ERRO: comando inválido. Comandos disponíveis: CF, RF, LF, CC, RC, LC, AL, DV, FS" << endl;
    }
  }

  return 0;
}
