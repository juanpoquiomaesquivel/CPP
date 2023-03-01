#include <iostream>
#include <limits>
#include <vector>
#include "FizzBuzz.hpp"

void fizz_buzz_game();

int main()
{
    fizz_buzz_game();

    return EXIT_SUCCESS;
}

void fizz_buzz_game()
{
    int limit;
    bool is_correct = false;

    std::cout << "Fizz Buzz Game" << std::endl;

    do
    {
        std::cout << "Enter a limit: "; // https://stackoverflow.com/questions/16934183/integer-validation-for-input
        std::cin >> limit;

        if (std::cin.good())
        {
            if (limit > 0)
                is_correct = true;
            else
                std::cout << "-- Please enter a limit greater than zero --" << std::endl;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "-- Please enter a correct value --" << std::endl;
        }
    }
    while (!is_correct);

    std::vector<std::string> vec = FizzBuzz::play(limit);

    std::cout << "Showing results..." << std::endl;

    for (std::string data : vec)
        std::cout << data << std::endl;
}
