#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int len,wid;
    cin>>len>>wid;
    vector<vector<int>> arr1(len,vector<int>(wid));
    vector<vector<int>> arr2(len,vector<int>(wid));

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            cin>>arr1[i][j];
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            cin>>arr2[i][j];
        }
    }
    vector<vector<int>> result(len,vector<int>(wid));
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            result[i][j]=arr1[i][j]*arr2[i][j];
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}