#include <vector>

int score(const std::vector<int> &dice)
{
    std::vector <int> count(6, 0);

    for (int i = 0; i < dice.size(); i++)
    {
        count[dice[i] - 1]++;
    }

    int Score = 0;

    if(count[0] == 1)
        Score += 100;
    else if(count[0] == 2)
        Score += 200;
    else if(count[0] == 3)
        Score += 1000;
    else if(count[0] == 4)
        Score += 1100;
    else if(count[0] == 5)
        Score += 1200;
    else if(count[0] == 6)
        Score += 2000;

    if(count[1] >= 3)
        Score += 200;
    
    if(count[2] >= 3)
        Score += 300;

    if(count[3] >= 3)
        Score += 400;

    if (count[4] == 1)
        Score += 50;
    else if(count[4] == 2)
        Score += 100;
    else if(count[4] == 3)
        Score += 500;
    else if(count[4] == 4)
        Score += 550;
    else if(count[4] == 5)
        Score += 600;
    else if(count[4] == 6)
        Score += 1000;
    
    if(count[5] >= 3)
        Score += 600;

    return Score;
}