#include <string>
#include <vector>
#include <istream>
#include <sstream>

std::string highestScoringWord(const std::string &text)
{
    int highest = 0;
    std::string answer;

    std::istringstream iss(text);// istringstream is an input stream class to operate on strings

    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());
    // 这行代码创建了一个std::vector<std::string>类型的向量words，用于存储分割后的单词。
    // std::istream_iterator<std::string>{iss}创建了一个输入流迭代器，它从iss中读取字符串。这个迭代器会按空白字符（空格、换行等）分割输入流中的内容，每次迭代返回一个单词。
    // std::istream_iterator<std::string>()是一个表示输入流结束的迭代器。当从iss中读取完所有内容后，当前迭代器会与这个结束迭代器相等，这时循环结束。
    // 这两个迭代器作为std::vector<std::string>的构造函数的参数，意味着words向量会被初始化为从iss中读取的所有单词的集合。

    for (auto word : words)
    {
        int score = 0;
        for (auto c : word)
            score += ((int)c) - 96;// The ASCII value of 'a' is 97, so subtracting 96 gives the value of the character
        if (score > highest)
        {
            highest = score;
            answer = word;
        }
    }
    return answer;
}