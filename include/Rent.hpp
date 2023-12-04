#ifndef RENT_HPP
#define RENT_HPP

#include "Client.hpp"
#include "Media.hpp"
#include <vector>
#include <string>
#include <map>

using namespace std;

class Rent
{
private:
    Client *_client;
    vector<Media *> _medias;
    bool _active;
    float _paymentAmount;

    /**
     * @brief Método que imprime um recibo de aluguel.
     */
    void printRentReceipt();
    /**
     * @brief Método que imprime um recibo de devolução aluguel.
     */
    void printDevolutionReceipt(map<int, float> pricesByMediaCode);

    /**
     * @brief Método que informa o preço de cada mídia, mapeada pelo respectivo código.
     *
     * @return Map de preços.
     */
    map<int, float> calculatePrice(int numberOfDays);

    /**
     * @brief Método que informa o preço da mídia de acordo com o múemro de dias alugados.
     *
     * @return Float do preço.
     */
    float calculatePrice(int numberOfDays, Media *media);

public:
    /**
     * @brief Método que constrói um aluguel.
     */
    Rent(Client *client, vector<Media *> medias) : _client(client), _medias(medias)
    {
        _active = true;
    };
    /**
     * @brief Método que informa o cliente que alugou.
     *
     * @return Cliente do aluguel.
     */
    Client *getClient();
    /**
     * @brief Método que informa as mídias alugadas.
     *
     * @return Vetor de mídias.
     */
    vector<Media *> getMedias();
    /**
     * @brief Método que informa o somatório dos valores do aluguel.
     *
     * @return Float somatório dos valores.
     */
    float getPaymentAmount();
    /**
     * @brief Método que informa se um aluguel está ativo ou não.
     *
     * @return Bool de atividade do aluguel.
     */
    bool isActive();
    /**
     * @brief Método que adiciona as mídias para o aluguel.
     */
    void setMedias(vector<Media *> medias);
    /**
     * @brief Método que representa a devolução de mídia.
     */
    void returnRent(int numberOfDays);
    /**
     * @brief Método que imprime um relatório.
     */
    void printRentReport();
};

#endif