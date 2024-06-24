#include <string>
#include <map>
// PS. The Morse code table is preloaded for you as a dictionary, feel free to use it

std::map <std::string, std::string> MORSE_CODE = {
    {".-", "A"}, {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"}, {".", "E"},
    {"..-.", "F"}, {"--.", "G"}, {"....", "H"}, {"..", "I"}, {".---", "J"},
    {"-.-", "K"}, {".-..", "L"}, {"--", "M"}, {"-.", "N"}, {"---", "O"},
    {".--.", "P"}, {"--.-", "Q"}, {".-.", "R"}, {"...", "S"}, {"-", "T"},
    {"..-", "U"}, {"...-", "V"}, {".--", "W"}, {"-..-", "X"}, {"-.--", "Y"},
    {"--..", "Z"},
    {"-----", "0"}, {".----", "1"}, {"..---", "2"}, {"...--", "3"}, {"....-", "4"},
    {".....", "5"}, {"-....", "6"}, {"--...", "7"}, {"---..", "8"}, {"----.", "9"},
    {".-.-.-", "."}, {"--..--", ","}, {"..--..", "?"}, {".----.", "'"}, {"-.-.--", "!"},
    {"-..-.", "/"}, {"-.--.", "("}, {"-.--.-", ")"}, {".-...", "&"}, {"---...", ":"},
    {"-.-.-.", ";"}, {"-...-", "="}, {".-.-.", "+"}, {"-....-", "-"}, {"..--.-", "_"},
    {".-..-.", "\""}, {"...-..-", "$"}, {".--.-.", "@"}
};

#include <regex> // regex is a header file that provides a way of searching a string using regular expressions

std::string decodeMorse(std::string morseCode)
{
    const std::regex morse("([^\\s]+|\\s{3})");
    // morse is a regular expression that matches a sequence of characters that are not whitespace or a sequence of three whitespaces
    // [^\\s]+ matches one or more characters that are not whitespace
    // | is the alternation operator that matches either the left or the right expression
    // \\s{3} matches three whitespaces
    
    std::string decoded;

    auto begin = morseCode.begin() + morseCode.find_first_not_of(' ');
    // find_first_not_of returns the index of the first character in the string that is not a whitespace

    auto end = morseCode.begin() + morseCode.find_last_not_of(' ') + 1;
    // find_last_not_of returns the index of the last character in the string that is not a whitespace

    for (auto it = std::sregex_iterator(begin, end, morse); it != std::sregex_iterator(); ++it)
    {
        // std::sregex_iterator is an iterator that iterates over the matches of a regular expression in a string
        // it is constructed with the string to search and the regular expression to match
        // it is incremented to the next match with the ++ operator
        
        // it!= std::sregex_iterator() is the condition that checks if the iterator is not at the end of the matches

        std::string str = it->str();// it->str() returns the matched string
        decoded += str == "   " ? " " : MORSE_CODE[str];
    }

    return decoded;
}