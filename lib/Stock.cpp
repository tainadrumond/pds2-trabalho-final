#include "../include/Stock.hpp"

Stock::Stock()
{
}

Stock::~Stock()
{
}

void Stock::increment(int id)
{
    if (_stock.find(id) == _stock.end())
        _stock[id] = 1;
    else
        _stock[id]++;
}

void Stock::decrement(int id)
{
    if (_stock.find(id) != _stock.end())
        _stock[id]--;
}

int Stock::getStock(int id)
{
    if (_stock.find(id) == _stock.end())
        return 0;
    else
        return _stock[id];
}