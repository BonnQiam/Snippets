#include <string>
#include <vector>
#include <iostream>

#define isdigit(c) ((c) >= '0' && (c) <= '9')
#define None -1

class Cubes
{
public:
    static std::string isSumOfCubes(std::string &str);
};

std::string Cubes::isSumOfCubes(std::string &str)
{
    std::vector<int> Cubes;// the elements are the cubes of the numbers that are the sum of the cubes of their digits
    int AllSum = 0;
    
    // traverse the string to find the numbers
    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])){// isdigit is a function that checks if a character is a digit
            std::cout << "str[i]: " << str[i] << std::endl;

            int DigitSum = 0;
            int CubeSum = 0;
            int j = i;
            
            int count = 0;
            while(j < str.size() && isdigit(str[j])){
                count++;
                if(count > 3){
                    j--;
                    break;
                }

                DigitSum = DigitSum * 10 + (str[j] - '0');
                CubeSum += (str[j] - '0') * (str[j] - '0') * (str[j] - '0');
                j++;
            }

            if(DigitSum == CubeSum){
                Cubes.push_back(DigitSum);
                AllSum += DigitSum;
            }

            i = j;
        }
    }

    std::cout << "AllSum: " << AllSum << std::endl;

    if(Cubes.size() == 0)
        return "Unlucky";

    Cubes.push_back(AllSum);

    // create the result string
    std::string result = "";
    
    for(int i = 0; i < Cubes.size(); i++){
        result += std::to_string(Cubes[i]);
        if(i != Cubes.size() - 1)
            result += " ";
    }
    result += " Lucky";
    return result;
}

int main()
{
    //std::string str = "aqdf& 0 1 xyz 153 777.777";
    
    std::string str = "&z _upon 407298a --- ???ry, ww/100 I thought, 631str*ng and w===y -721&()";
    //std::string str = "Once 1000upon a midnight 110dreary, while100 I pondered, 9026315weak and weary -827&()";
    
    //std::string str = "932";
    std::string result = Cubes::isSumOfCubes(str);

    std::cout << result << std::endl;
    
    return 0;
}