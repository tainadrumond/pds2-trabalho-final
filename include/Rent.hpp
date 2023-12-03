#ifndef RENT_HPP
#define RENT_HPP

#include <vector>
#include <chrono>

class Rent
{
private:
    int _idCostumer;
    std::vector<int> _idMedia;
    std::chrono::system_clock::time_point _rentDate;
    std::chrono::system_clock::time_point _giveBackDate;
    bool _isClosed;

public:
    Rent(int idCostumer, std::vector<int> idMedia);
    ~Rent();

    int getIdCostumer();
    std::vector<int> getIdMedia();

    void close();
    bool isClosed();

    int getDays();
};

#endif