#ifndef SRC_FRAMEWORK_UTIL_UTILITY
#define SRC_FRAMEWORK_UTIL_UTILITY
#include <sstream>

namespace sf
{
    class Sprite;
    class Text;
}

template <typename T>
std::string toString(const T& value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#endif /* SRC_FRAMEWORK_UTIL_UTILITY */
