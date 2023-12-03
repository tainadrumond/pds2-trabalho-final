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
    int _sumRating;
    int _numRating;

public:
    Media(int id, std::string title, int copies, float price) : _id(id), _title(title), _copies(copies), _price(price)
    {
        _idCounter++;
        _sumRating = 0;
        _numRating = 0;
    };

    int getId();
    std::string getTitle();
    int getCopies();
    float getPrice();

    std::string virtual getMediaType() = 0;

    void addRating(int rating);
    float getAverageRating();
};

#endif