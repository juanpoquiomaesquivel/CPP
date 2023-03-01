#include "FizzBuzz.hpp"

#include <cstdbool>
#include <iostream>
#include <string>
#include <vector>

bool is_multiple(int number1, int number2);

std::vector<std::string> FizzBuzz::play(const int limit)
{
    std::vector<std::string> vec;

    if (limit > 0)
    {
        std::string str;

        for (int i = 1; i <= limit; i++)
        {
            str = "";

            if (is_multiple(i, 3))
                str = str + "Fizz";

            if (is_multiple(i, 5))
                str = str + "Buzz";

            vec.push_back(str.compare("") != 0 ? str : std::to_string(i)); // https://stackoverflow.com/questions/4668760/converting-an-int-to-stdstring
        }
    }

    return vec;
}

bool is_multiple(int number1, int number2)
{
    return number1 % number2 == 0;
}
