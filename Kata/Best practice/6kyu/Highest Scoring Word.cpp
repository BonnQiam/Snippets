#include <iostream>
#include <string>
#include <sstream> // stringstream is a stream class to operate on strings

std::string highestScoringWord(const std::string &str)
{
    std::cout << str << std::endl;

    std::istringstream stm(str);// istringstream is an input stream class to operate on strings
    std::string token, maxString;
    long maxValue = 0;

    // GetValue is a lambda function that takes a string and returns the sum of the characters' values
    auto GetValue = [](const std::string &s)
    {
        long r = 0;
        for (auto c : s)
            r += int(c) - int('a') + 1;

        return r;
    };

    while (std::getline(stm, token, ' '))
    // getline extracts characters from the stream until a delimiter is found
    // stm as the first argument is the stream to read from
    // token as the second argument is the string to store the extracted characters
    // ' ' as the third argument is the delimiter to stop reading
    {
        long actValue = GetValue(token);
        if (actValue > maxValue)
        {
            maxValue = actValue;
            maxString = token;
        }
    }

    return maxString;
}