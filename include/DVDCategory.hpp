#ifndef DVDCATEGORY_HPP
#define DVDCATEGORY_HPP

#include <string>

class DVDCategory
{
private:
    std::string _name;
    float _price;
    bool _fixedPrice;

public:

  /**
 * @brief Construtor do DVD category.
 */
    DVDCategory(std::string name, float price, bool fixedPrice) : _name(name), _price(price), _fixedPrice(fixedPrice){};
  /**
 * @brief Método que informa o nome da categoria.
 * 
 * @return Nome da categoria.
 */
    std::string getName();
  /**
 * @brief Método que informa o preço da categoria.
 * 
 * @return Preço da categoria.
 */
    float getPrice();
  /**
 * @brief Método que informa se o preço é fixo ou não.
 * 
 * @return Bool nos casos que os preços são fixos ou não.
 */
    bool hasFixedPrice();
};

#endif