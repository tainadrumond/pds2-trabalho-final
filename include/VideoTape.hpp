#ifndef VIDEOTAPE_HPP
#define VIDEOTAPE_HPP

#include "Media.hpp"
#include <string>

const int VIDEO_TAPE_PRICE = 5;

class VideoTape : public Media
{
private:
    float const _priceForRewoundDevolution = 2;
    bool const _fixedPrice = true;

public:
  /**
 * @brief Construtor do VideoTape
 *
 * Constrói um objeto VideoTape de acordo com determinados parâmetros.
 *
 * @param title Título do filme representado.
 * @param copies Quantidade de cópias.
 * @param ID Número de identificação usado.
 */
    VideoTape(std::string title, int copies, int id) : Media(id, title, copies, VIDEO_TAPE_PRICE, _fixedPrice){};
  /**
 * @brief Método que informa o preço da fita.
 *
 * Retorna o preço do objeto que o chamou.
 *
 * @return Atributo do preço.
 */
    float getPrice();
     /**
 * @brief Método que informa o preço da fita rebobinada.
 *
 * Retorna o preço do objeto que o chamou.
 *
 * @return Atributo do preço.
 */
    float getPriceForRewoundDevolution();
 /**
 * @brief Método que informa o tipo de mídia.
 *
 * Retorna o tipo da mídia do objeto que o chamou.
 *
 * @return Tipo da mídia.
 */
    std::string getMediaType();
};

#endif