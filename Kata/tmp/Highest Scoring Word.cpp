//https://www.codewars.com/kata/57eb8fcdf670e99d9b000272/train/cpp

#include <string>
#include <map>

std::string highestScoringWord(const std::string &str)
{
    std::map<char, int> alphabet = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, 
        {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, 
        {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, 
        {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, 
        {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}
    };

    int highestScore = 0;
    std::string word = "";
    std::string highestScoringWord = "";

    for(auto itr = str.begin(); itr != str.end(); itr++)
    {
        if(*itr == ' ' || itr == str.end() - 1)
        {            

            if(itr == str.end() - 1 && *itr != ' ')
                word += *itr;

            //calculate the score of the word
            int score = 0;
            for(auto itr2 = word.begin(); itr2 != word.end(); itr2++)
            {
                score += alphabet[*itr2];
            }

            if(score > highestScore)
            {
                highestScore = score;
                highestScoringWord = word;
            }

            word = "";
        }
        else
        {
            word += *itr;
        }
    }
    
    return highestScoringWord;
}