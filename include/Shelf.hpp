//Must be used in a vector, inside store.hpp
#ifndef SHELF_HPP
#define SHELF_HPP

#include <vector>
#include <Media.hpp>

class Shelf
{
private:
  static int idCounter;
  
  std::vector<Media> itens;

public:
  Shelf(std::vector<Media> itens);
  void Shelf::ShelfAdd(Media inten);
  Media Shelf::ShelfSearch(Media inten);
};

#endif