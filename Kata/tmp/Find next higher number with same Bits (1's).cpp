// https://www.codewars.com/kata/56bdd0aec5dc03d7780010a5/train/cpp
#include <iostream>
#include <vector>

#define NoneExist -1

int nextHigher(int value)
{   
    std::cout << "Value is " << value << std::endl;

    std::vector<int> bits;// first bit is the least significant bit and the last bit is the most significant bit

    while (value > 0)
    {
        bits.push_back(value % 2);
        value /= 2;
    }

#if 1
    
    for (int i = 0; i < bits.size(); i++)
    {
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl;
#endif

    int FirstIndexZero_BeforeOne = NoneExist;
    int LastIndexZero_BeforeOne = NoneExist;
    int IndexZero_AfterOne  = NoneExist;

    for (int i = 0; i < bits.size()-1; i++)
    {
        if(bits[i] == 1 && bits[i+1] == 0)
        {
            IndexZero_AfterOne = i+1;
            break;
        }
    }


    int End = (IndexZero_AfterOne == NoneExist) ? bits.size() : IndexZero_AfterOne-1;

    for(int i = 0; i < End; i++)
    {
        if(bits[i] == 0)
        {
            FirstIndexZero_BeforeOne = i;
            break;
        }
    }

    if(FirstIndexZero_BeforeOne != NoneExist)
    {
        for(int i = FirstIndexZero_BeforeOne+1; i < End; i++)
        {
            if(bits[i] == 0)
            {
                LastIndexZero_BeforeOne = i;
            }
        }

        if(LastIndexZero_BeforeOne == NoneExist)
        {
            LastIndexZero_BeforeOne = FirstIndexZero_BeforeOne;
        }
    }

#if 1
    std::cout << "FirstIndexZero_BeforeOne is " << FirstIndexZero_BeforeOne << std::endl;
    std::cout << "LastIndexZero_BeforeOne is " << LastIndexZero_BeforeOne << std::endl;
    std::cout << "IndexZero_AfterOne is " << IndexZero_AfterOne << std::endl;
#endif

    if(FirstIndexZero_BeforeOne == NoneExist && IndexZero_AfterOne == NoneExist)
    {
        bits[bits.size()-1] = 0;
        bits.push_back(1);
    }
    else if(FirstIndexZero_BeforeOne == NoneExist && IndexZero_AfterOne != NoneExist)
    {
        bits[IndexZero_AfterOne] = 1;
        bits[IndexZero_AfterOne-1] = 0;
    }
    else{
        if(IndexZero_AfterOne == NoneExist)
        {
            int CountOne = bits.size() - LastIndexZero_BeforeOne -1;

            for(int i = 1; ; i++)
            {
                if(i > CountOne-1 || CountOne == 1)
                    break;
                bits[FirstIndexZero_BeforeOne+i-1] = 1;
            }

            for(int i = FirstIndexZero_BeforeOne+CountOne-1; i < bits.size(); i++)
            {
                bits[i] = 0;
            }

            bits.push_back(1);
        }
        else{
            int CountOne = IndexZero_AfterOne - LastIndexZero_BeforeOne - 1;

            std::cout << "CountOne is " << CountOne << std::endl;

            for(int i = 1; ; i++)
            {   
                if(i > CountOne-1 || CountOne == 1)
                    break;
                bits[FirstIndexZero_BeforeOne+i-1] = 1;
            }

            for(int i = FirstIndexZero_BeforeOne+CountOne-1; i < IndexZero_AfterOne; i++)
            {
                bits[i] = 0;
            }

            bits[IndexZero_AfterOne] = 1;
        }
    }

#if 1
    for (int i = 0; i < bits.size(); i++)
    {
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl;
#endif

    int result = 0;

    for (int i = bits.size()-1; i >= 0; i--)
    {
        result = result * 2 + bits[i];
    }

    return result;
}

int main()
{
    //int value = 128;
    //int value = 1;
    //int value = 1022;
    //int value = 127;
    int value = 1253343;

    //int value = 90443704;

    int result = nextHigher(value);

    std::cout << "The next higher number with the same number of bits is: " << result << std::endl;

    return 0;
}