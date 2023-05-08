#include "Hasher.hpp"

#include <iostream>
#include <string>

int main()
{
    std::string user_input;

    std::cout << "Enter your input" <<std::endl;
    std::cin >> user_input;

    hash<SHA256>(user_input);

    return 0;

}