#include<iostream>
#include<vector>
#include<deque> 
using namespace std;

void move(vector<deque<int>>& matrix, int x, int y)
{
    x--; y--;
    int temp = matrix[x].front();
    matrix[x].pop_front();
    matrix[y].push_back(temp);
}

int getNum(const vector<deque<int>>& matrix, int x, int y)
{
    x--;
    y--;
    
    if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[x].size())
    {
        return matrix[x][y];
    }
    return -1;
}

int main()
{
    
    int row, col, Q;
    cin >> row >> col >> Q;
    
    vector<deque<int>> matrix(row);
    for(int i = 0; i < row; i++)
    {
        matrix[i].resize(col);
        for(int j = 0; j < col; j++)
        {
            matrix[i][j] = i * col + j + 1;
        }
    }
    
    while(Q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1)
            move(matrix, x, y);
        else
            cout << getNum(matrix, x, y) << '\n';
    }
    return 0;
}