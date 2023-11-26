#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>

class Media {
    private:
        int _id;
        std::string _title;
        int _copies;
        float _price;

    public:
        Media(std::string title, int copies, int id, float price): _title(title), _copies(copies), _id(id), _price(price) {};

        int getId();
        std::string getTitle();
        int getCopies();
        float getPrice();

        void rent();
        void virtual returnMedia();
};

#endif