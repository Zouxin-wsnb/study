#include <iostream>
#include <vector>
#include <string>
using namespace std;

auto spread(vector<bool>& people,vector<pair<int,int>> relat,int turns)
{
    for(int turn=0;turn<turns;turn++)
    {
        vector<bool> new_people = people;
        for(int i=0;i<relat.size();i++)
        {
           if(people[relat[i].first]||people[relat[i].second])
           {
             people[relat[i].second]=people[relat[i].first]=true;
           } 
        }
        people = new_people;
    }
}

int main()
{
    int n,m;cin>>n>>m;
    vector<bool> people(n,false);
    vector<pair<int,int>> relat(m);
    int turn;cin>>turn;
    int first;cin>>first;
    people[first-1]=true;
    for(int i=0;i<m;++i)
    {
        int a,b;cin>>a>>b;
        relat[i]={a-1,b-1};
    }
    spread(people,relat,turn);
    int num=0;
    for(bool i:people)
    {
        if(i)++num;
    }
    cout<<num;
    return 0;
}