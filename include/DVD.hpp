#ifndef DVD_HPP
#define DVD_HPP

#include "Media.hpp"
#include "DVDCategory.hpp"

class DVD: public Media {
    private:
        DVDCategory* _category;
    
    public:
        DVD(std::string title, int copies, int id, DVDCategory* category): _category(category), Media(title, copies, id, category->getPrice()) {};
};

#endif