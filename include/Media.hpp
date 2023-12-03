#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>

class Media
{
private:
    int _id;
    std::string _title;
    bool _adult;
    float _sumRating;
    int _countRating;

public:
    Media(int id, std::string title, bool adult);
    ~Media();

    int getId();
    std::string getTitle();

    bool isAdult();

    float virtual getRentPrice(int rentDays) = 0;

    void addRating(int rating);
    float getRating();
};

#endif