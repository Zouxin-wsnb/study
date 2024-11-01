#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string input;cin>>input;
    vector<pair<char,int>> get;
    for(int i=0;i<input.size();i++)
    {
        if(get.size()==0||get[get.size()-1].first!=input[i])
        {
            get.push_back(make_pair(input[i],1));
        }
        else
        {
            get[get.size()-1].second++;
        }
    }

    string output;
    for(int i=0;i<get.size();i++)
    {
        output+=get[i].first;
        if(get[i].second>1)
        output+=to_string(get[i].second);
    }
    cout<<output;
    return 0;
}