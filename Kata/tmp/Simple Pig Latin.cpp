#include <string>
#include <sstream> // stringstream is a stream class to operate on strings

std::string pig_it(std::string str)
{
    std::istringstream stm(str);
    std::string token, result;

    while (std::getline(stm, token, ' '))
    {
        if (token.size() == 1 && !isalpha(token[0]))// isalpha returns true if the character is an alphabet
        {
            result += token + " ";
        }
        else
        {
            result += token.substr(1) + token[0] + "ay ";// substr returns a newly constructed string object with its value initialized to a copy of a substring of this object
        }
    }

    return result.substr(0, result.size() - 1);
}