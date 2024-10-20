#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> gamecontrol(vector<vector<int>> game2468,string current)
{
    if(current =="U")
    {
        for(int i=0;i<4;i++)
        {   
            if(game2468[3][i]!=0)
            {
                if(game2468[2][i]!=0)
                {
                  game2468[2][i] += game2468[3][i];
                  game2468[3][i] = 0;
                }
                else if(game2468[2][i]==0)
                {
                    if(game2468[1][i]!=0)
                    {
                        game2468[1][i] += game2468[3][i];
                        game2468[3][i] = 0;
                    }
                    else if(game2468[1][i]==0)
                    {
                        if(game2468[0][i]!=0)
                        {
                            game2468[0][i] += game2468[3][i];
                            game2468[3][i] = 0;
                        }
                        else if(game2468[0][i]==0)
                        {
                            game2468[0][i] = game2468[3][i];
                            game2468[3][i] = 0;
                        }
                    }
                }
            }
            if(game2468[3][i]==0)
            {
                if(game2468[2][i]!=0)
                {
                    if(game2468[1][i]!=0)
                    {
                        game2468[1][i] += game2468[2][i];
                        game2468[2][i] = 0;
                    }
                    else if(game2468[1][i]==0)
                    {
                        if(game2468[0][i]!=0)
                        {
                            game2468[0][i] += game2468[2][i];
                            game2468[2][i] = 0;
                        }
                        else if(game2468[0][i]==0)
                        {
                            game2468[0][i] = game2468[2][i];
                            game2468[2][i] = 0;
                        }
                    }
                }
                if(game2468[2][i]==0)
                {
                    if(game2468[1][i]!=0)
                    {
                        if(game2468[0][i]!=0)
                        {
                            game2468[0][i] += game2468[1][i];
                            game2468[1][i] = 0;
                        }
                        else if(game2468[0][i]==0)
                        {
                            game2468[0][i] = game2468[1][i];
                            game2468[1][i] = 0;
                        }
                    }
                }
            }
        }
        return game2468;
    }
    else if(current =="D")
    {
        for(int i=0;i<4;i++)
        {   
            if(game2468[0][i]!=0)
            {
                if(game2468[1][i]!=0)
                {
                  game2468[1][i] += game2468[0][i];
                  game2468[0][i] = 0;
                }
                else if(game2468[1][i]==0)
                {
                    if(game2468[2][i]!=0)
                    {
                        game2468[2][i] += game2468[0][i];
                        game2468[0][i] = 0;
                    }
                    else if(game2468[2][i]==0)
                    {
                        if(game2468[3][i]!=0)
                        {
                            game2468[3][i] += game2468[0][i];
                            game2468[0][i] = 0;
                        }
                        else if(game2468[3][i]==0)
                        {
                            game2468[3][i] = game2468[0][i];
                            game2468[0][i] = 0;
                        }
                    }
                }
            }
            if(game2468[0][i]==0)
            {
                if(game2468[1][i]!=0)
                {
                    if(game2468[2][i]!=0)
                    {
                        game2468[2][i] += game2468[1][i];
                        game2468[1][i] = 0;
                    }
                    else if(game2468[2][i]==0)
                    {
                        if(game2468[3][i]!=0)
                        {
                            game2468[3][i] += game2468[1][i];
                            game2468[1][i] = 0;
                        }
                        else if(game2468[3][i]==0)
                        {
                            game2468[3][i] = game2468[1][i];
                            game2468[1][i] = 0;
                        }
                    }
                }
                if(game2468[1][i]==0)
                {
                    if(game2468[2][i]!=0)
                    {
                        if(game2468[3][i]!=0)
                        {
                            game2468[3][i] += game2468[2][i];
                            game2468[2][i] = 0;
                        }
                        else if(game2468[3][i]==0)
                        {
                            game2468[3][i] = game2468[2][i];
                            game2468[2][i] = 0;
                        }
                    }
                }
            }
        }
        return game2468;
    }
    else if(current =="L")
    {
        for(int i=0;i<4;i++)
        {   
            if(game2468[i][3]!=0)
            {
                if(game2468[i][2]!=0)
                {
                  game2468[i][2] += game2468[i][3];
                  game2468[i][3] = 0;
                }
                else if(game2468[i][2]==0)
                {
                    if(game2468[i][1]!=0)
                    {
                        game2468[i][1] += game2468[i][3];
                        game2468[i][3] = 0;
                    }
                    else if(game2468[i][1]==0)
                    {
                        if(game2468[i][0]!=0)
                        {
                            game2468[i][0] += game2468[i][3];
                            game2468[i][3] = 0;
                        }
                        else if(game2468[i][0]==0)
                        {
                            game2468[i][0] = game2468[i][3];
                            game2468[i][3] = 0;
                        }
                    }
                }
            }
            if(game2468[i][3]==0)
            {
                if(game2468[i][2]!=0)
                {
                    if(game2468[i][1]!=0)
                    {
                        game2468[i][1] += game2468[i][2];
                        game2468[i][2] = 0;
                    }
                    else if(game2468[i][1]==0)
                    {
                        if(game2468[i][0]!=0)
                        {
                            game2468[i][0] += game2468[i][2];
                            game2468[i][2] = 0;
                        }
                        else if(game2468[i][0]==0)
                        {
                            game2468[i][0] = game2468[i][2];
                            game2468[i][2] = 0;
                        }
                    }
                }
                if(game2468[i][2]==0)
                {
                    if(game2468[i][1]!=0)
                    {
                        if(game2468[i][0]!=0)
                        {
                            game2468[i][0] += game2468[i][1];
                            game2468[i][1] = 0;
                        }
                        else if(game2468[i][0]==0)
                        {
                            game2468[i][0] = game2468[i][1];
                            game2468[i][1] = 0;
                        }
                    }
                }
            }
        }
        return game2468;
    }
    else if(current =="R")
    {
        for(int i=0;i<4;i++)
        {   
            if(game2468[i][0]!=0)
            {
                if(game2468[i][1]!=0)
                {
                  game2468[i][1] += game2468[i][0];
                  game2468[i][0] = 0;
                }
                else if(game2468[i][1]==0)
                {
                    if(game2468[i][2]!=0)
                    {
                        game2468[i][2] += game2468[i][0];
                        game2468[i][0] = 0;
                    }
                    else if(game2468[i][2]==0)
                    {
                        if(game2468[i][3]!=0)
                        {
                            game2468[i][3] += game2468[i][0];
                            game2468[i][0] = 0;
                        }
                        else if(game2468[i][3]==0)
                        {
                            game2468[i][3] = game2468[i][0];
                            game2468[i][0] = 0;
                        }
                    }
                }
            }
            if(game2468[i][0]==0)
            {
                if(game2468[i][1]!=0)
                {
                    if(game2468[i][2]!=0)
                    {
                        game2468[i][2] += game2468[i][1];
                        game2468[i][1] = 0;
                    }
                    else if(game2468[i][2]==0)
                    {
                        if(game2468[i][3]!=0)
                        {
                            game2468[i][3] += game2468[i][1];
                            game2468[i][1] = 0;
                        }
                        else if(game2468[i][3]==0)
                        {
                            game2468[i][3] = game2468[i][1];
                            game2468[i][1] = 0;
                        }
                    }
                }
                if(game2468[i][1]==0)
                {
                    if(game2468[i][2]!=0)
                    {
                        if(game2468[i][3]!=0)
                        {
                            game2468[i][3] += game2468[i][2];
                            game2468[i][2] = 0;
                        }
                        else if(game2468[i][3]==0)
                        {
                            game2468[i][3] = game2468[i][2];
                            game2468[i][2] = 0;
                        }
                    }
                }
            }
        }
         return game2468;
    }       
}

vector<vector<int>> getresult(vector<vector<int>> game2468,int input,vector<string> play)
{
    for(int i=0;i<input;i++)
    {
        game2468 = gamecontrol(game2468,play[i]);
    }
    return game2468;
}

int main()
{
    vector<vector<int>> game2468(4, vector<int>(4));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> game2468[i][j];
        }
    }
    int input;cin >> input;
    vector<string> play(input);
    for(int i=0; i<input; i++)
    {
        cin >> play[i];
    }
    vector<vector<int>> result = getresult(game2468,input,play);
    // Optional: Print the matrix to verify input
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}