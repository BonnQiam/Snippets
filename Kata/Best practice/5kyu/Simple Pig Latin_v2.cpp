#include<iostream>
#include<sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string pig_it(string str)
{
	
	string punctuation = "!.,:;?";// define punctuation, which will be used to check if the first character of a word is a punctuation
	string result = "";
	stringstream ss;
	ss << str;// insert the string str into the stream ss

	for (char ch; ss.get(ch);) { 
        //ss.get(ch) extracts a character from the stream and stores it in ch

		if (isspace(ch))// isspace returns true if the character is a whitespace character
			result += ch;
				
		else {
			ss.putback(ch); //read a word from the stream
			string word;
			ss >> word;// extract a word from the stream and store it in word
			
			if (find(punctuation.begin(), punctuation.end(), word[0]) == punctuation.end()) {
				word.push_back(word[0]);
				word.erase(word.begin());
				word.push_back('a');
				word.push_back('y');
			}
			result += word;
		}
	}

	return result;
}

std::string pig_it_v2(std::string str)
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