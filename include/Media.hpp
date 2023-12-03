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
    Media(int id, std::string title, int copies, float price, bool fixedPrice) : _id(id), _title(title), _copies(copies), _price(price), _fixedPrice(fixedPrice)
    {
        _idCounter++;
        _sumRating = 0;
        _numberOfRatings = 0;
    };

    int getId();
    std::string getTitle();
    int getCopies();
    float getPrice();
    bool hasFixedPrice();

    std::string virtual getMediaType() = 0;

    void addRating(int rating);
    float getRating();
};

#endif