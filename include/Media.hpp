#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>

class Media {
    private:
        static int _idCounter;

        int _id;
        std::string _title;
        int _copies;
        float _price;

    public:
        Media(std::string title, int copies, float price): _title(title), _copies(copies), _price(price) {
            _idCounter++;
            _id = _idCounter; 
        };

        int getId();
        std::string getTitle();
        int getCopies();
        float getPrice();

        void rent();
        void virtual returnMedia();
};

#endif