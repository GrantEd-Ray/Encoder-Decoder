#include <iostream>
#include <string>
#include "Text.h"


int main() {
    std::string t;
    std::getline(std::cin, t);

    mt::Text a(t);
    std::cout << a.get_word(1) << std::endl;

    a.Encode();

    a.show();

    a.Decode();

    a.show();
    return 0;
}
