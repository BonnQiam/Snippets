#include <string>
#include <regex>
using namespace std;


string pig_it_v1(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    // reg is a regular expression object
    // (\\w) is the first capturing group, which matches any word character (alphanumeric & underscore)
    // (\\w*) is the second capturing group, which matches any word character (alphanumeric & underscore) zero or more times
    // (\\s|$) is the third capturing group, which matches any whitespace character or the end of the string

    return regex_replace(Z, reg, "$2$1ay$3");
    // regex_replace replaces all matches in the string Z that match the regular expression reg with the replacement string "$2$1ay$3"
    // $2 is the second capturing group, which matches any word character (alphanumeric & underscore) zero or more times
    // $1 is the first capturing group, which matches any word character (alphanumeric & underscore)
    // ay is the string "ay"
    // $3 is the third capturing group, which matches any whitespace character or the end of the string
}

std::string pig_it_v2(std::string str)
{
    return std::regex_replace(std::move(str), std::regex{"([a-zA-Z])(\\S*)"}, "$2$1ay");
    //std::regex{"([a-zA-Z])(\\S*)"} is a regular expression object that matches a word character followed by zero or more non-whitespace characters
    //"$2$1ay" is the replacement string that replaces the matched string with the second capturing group, the first capturing group, and the string "ay"
}