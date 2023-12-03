#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>

class Media
{
protected:
    static int _idCounter;
    int _id;
    std::string _title;
    int _copies;
    float _price;
    bool _fixedPrice;
    int _sumRating;
    int _numberOfRatings;

public:
/**
 * @brief Construtor do Media.
 *
 * Método que constrói um objeto Media de acordo com determinados parâmetros.
 *
 * @param ID Número de identificação usado.
 * @param title Título do filme representado.
 * @param copies Quantidade de cópias.
 * @param price Preço de aluguel da mídia.
 * @param fixedPrice Informa se o preço é fixo ou não.
 * 
 */
    Media(int id, std::string title, int copies, float price, bool fixedPrice) : _id(id), _title(title), _copies(copies), _price(price), _fixedPrice(fixedPrice)
    {
        _idCounter++;
        _sumRating = 0;
        _numberOfRatings = 0;
    };
 /**
 * @brief Método que informa o ID da fita.
 *
 * Quando chamado, retorna o ID do objeto que o chamou.
 *
 * @return Atributo do ID.
 */
    int getId();
 /**
 * @brief Método que informa o título da mídia.
 *
 * Quando chamado, retorna o título do objeto que o chamou.
 *
 * @return Atributo do título.
 */
    std::string getTitle();
 /**
 * @brief Método que informa a quantidade de cópias da mídia.
 *
 * Quando chamado, retorna a quantidade de cópias do objeto que o chamou.
 *
 * @return Atributo de cópias.
 */
    int getCopies();
     /**
 * @brief Método que informa o preço da mídia.
 *
 * Quando chamado, retorna o preço do objeto que o chamou.
 *
 * @return Atributo do preço.
 */
    float getPrice();
 /**
 * @brief Método que informa o preço fixo da mídia.
 *
 * Quando chamado, retorna o preço fixo do objeto que o chamou.
 *
 * @return Atributo do preço fixo.
 */
    bool hasFixedPrice();

 /**
 * @brief Método que informa o tipo de mídia.
 *
 * Quando chamado, retorna o tipo da mídia do objeto que o chamou (Este método foi redefinido em todas as classe filhas).
 *
 * @return Tipo da mídia.
 */
    std::string virtual getMediaType() = 0;

 /**
 * @brief Método que adiciona uma avaliação para a mídia.
 *
 * Quando chamado, Adiciona uma avaliação do usuário para a determinada mídia
 *
 */
    void addRating(int rating);
 /**
 * @brief Método que informa a avaliação dada.
 *
 * Quando chamado, retorna a avaliação que já foi dada anteriormente.
 *
 * @return Float da avaliação.
 */
    float getRating();
};

#endif