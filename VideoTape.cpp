#include <string>
#include "VideoTape.hpp"

VideoTape::VideoTape(std::string title, int copies, bool rewound) :
Media(title, copies), _rewound(rewound)
{
}

