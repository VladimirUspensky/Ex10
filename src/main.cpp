// Copyright 2020 VladimirUspensky
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
    std::string inf = "2 + 6 * 3 / (4 - 2)";
    std::string postf = infix2postfix(inf);
    std::cout << postf << std::endl;
    return 0;
}
