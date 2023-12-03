#ifndef STOCK_HPP
#define STOCK_HPP

#include <map>
#include <string>

class Stock
{
private:
    std::map<int, int> _stock;

public:
    Stock();
    ~Stock();

    void increment(int id);
    void decrement(int id);

    int getStock(int id);
};

#endif