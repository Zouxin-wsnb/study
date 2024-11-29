#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> num_before;

bool judge_happy(int n)
{
    if(n==1)
    {
        return true;
    }
    if(num_before.empty())
    {
        num_before.push_back(n);
    }
    else
    {
        for(int i=0;i<num_before.size();i++)
        {
            if(n==num_before[i])
            {
                return false;
            }
        }
        num_before.push_back(n);
    }
    int new_num=0;
    string str = to_string(n);
    for(int i=0;i<str.size();i++)
    {
        new_num += (str[i]-'0')*(str[i]-'0');
    }
    return judge_happy(new_num);
}

int main()
{
    int num;
    cin >> num;
    cout << (judge_happy(num)==true?"True":"False") << endl;
}