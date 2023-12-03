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

public:
    Media(int id, std::string title, int copies, float price, bool fixedPrice) : _id(id), _title(title), _copies(copies), _price(price), _fixedPrice(fixedPrice)
    {
        _idCounter++;
    };

    int getId();
    std::string getTitle();
    int getCopies();
    float getPrice();
    bool hasFixedPrice();

    std::string virtual getMediaType() = 0;
};

#endif