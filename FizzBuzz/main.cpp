#include <iostream>
#include <queue>
#include <cstdbool>
#include <limits>

using namespace std;

void play();
queue<string> fizz_buzz(size_t limit);
bool is_multiple(int number1, int number2);

int main()
{
    play();

    return EXIT_SUCCESS;
}

void play()
{
    short int limit;
    bool is_correct = false;

    cout << "Fizz Buzz Game" << endl;

    do
    {
        cout << "Enter a limit: "; // https://stackoverflow.com/questions/16934183/integer-validation-for-input
        cin >> limit;

        if (cin.good())
        {
            if (limit > 0)
                is_correct = true;
            else
                cout << "-- Please enter a limit greater than 0 --" << endl;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "-- Please enter a correct value --" << endl;
        }
    }
    while (!is_correct);

    queue<string> qu = fizz_buzz(limit);
    size_t len = qu.size();

    cout << "Showing results..." << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << qu.front() << endl;
        qu.pop();
    }
}

queue<string> fizz_buzz(size_t limit)
{
    queue<string> qu;
    string str;

    for (size_t i = 1; i <= limit; i++)
    {
        str = "";

        if (is_multiple(i, 3))
            str = str + "Fizz";

        if (is_multiple(i, 5))
            str = str + "Buzz";

        qu.push(str.compare("") != 0 ? str : to_string(i)); // https://stackoverflow.com/questions/4668760/converting-an-int-to-stdstring
    }

    return qu;
}

bool is_multiple(int number1, int number2)
{
    return number1 % number2 == 0;
}
