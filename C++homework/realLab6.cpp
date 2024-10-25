#include <iostream>
#include <vector>
#include <string>
using namespace std;

void hanoi(int n, int source, int target, int auxiliary, vector<string>& moves) 
{
    if (n == 1) 
    {   // 移动最小的盘子
        moves.push_back("move disk 1 from rod " + to_string(source) + " to rod " + to_string(target));
    } else 
    {   // 递归地将前n-1个盘子移动到辅助柱子
        hanoi(n - 1, source, auxiliary, target, moves);
        // 移动第n个盘子到目标柱子
        moves.push_back("move disk " + to_string(n) + " from rod " + to_string(source) + " to rod " + to_string(target));
        // 递归地将n-1个盘子从辅助柱子移动到目标柱子
        hanoi(n - 1, auxiliary, target, source, moves);
    }
}

void solve_hanoi(int n) 
{
    vector<string> moves;
    hanoi(n, 1, 3, 2, moves);
    cout << moves.size() << endl;
    for (const string& move : moves) 
    {
        cout << move << endl;
    }
}

int main() {
    int n;
    cin >> n;
    solve_hanoi(n);
    
    return 0;
}