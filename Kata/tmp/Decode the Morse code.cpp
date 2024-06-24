// https://www.codewars.com/kata/54b724efac3d5402db00065e/train/cpp
#include <string>
#include <map>
#include <iostream>
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


std::string decodeMorse(const std::string& morseCode) {
    // ToDo: Accept dots, dashes and spaces, return human-readable message
    std::string decoded;
    std::string word;

    auto itr_begin = morseCode.begin();

    while(*itr_begin == ' ') {
        ++itr_begin;
    }

    for(auto itr = itr_begin; itr != morseCode.end(); ++itr) {
        if( *itr == ' ' ) {
            if( *(itr+1) != ' ' ) {
                if( !word.empty() ) {
                    decoded += MORSE_CODE[word];
                    word.clear();
                }
            }
            else {
                if( !word.empty() ) {
                    decoded += MORSE_CODE[word];
                    word.clear();
                }
                itr += 2;
                while( *(itr+1) == ' ' ) {
                    ++itr;
                    if( itr == morseCode.end() - 1 ) {
                        break;
                    }
                }
                if( itr != morseCode.end() - 1 ) {
                    decoded += ' ';
                }
            }
        }
        else if ( (*itr != ' ') && (itr == morseCode.end() - 1) ) {
            word += *itr;
            decoded += MORSE_CODE[word];
        }
        else {
            word += *itr;
        }
    }

    return decoded;
}

int main() {
    //std::string morseCode = ".... . -.--   .--- ..- -.. .";
    std::string morseCode = ".... . -.--   .--- ..- -.. .";

    std::string decoded = decodeMorse(morseCode);
    std::cout << decoded << std::endl;
    return 0;
}