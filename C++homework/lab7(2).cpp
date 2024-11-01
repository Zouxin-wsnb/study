#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
    ifstream fin("input.txt",ios::in);
    ofstream fout("output.txt",ios::out| ios::trunc);
    string str1,str2;
    fin>>str1>>str2;
    
    vector<int> result(str1.size()+str2.size(),0);

    for(int i=str1.size()-1;i>=0;i--)
    {
        for(int j=str2.size()-1;j>=0;j--)
        {
            result[i+j+1]+=(str1[i]-'0')*(str2[j]-'0');
            result[i+j]+=result[i+j+1]/10;
            result[i+j+1]%=10;
        }
    }

    while(result.size() > 1&result[0]==0)
    {
        result.erase(result.begin());
    }

    string output;

    for(int i=0;i<result.size();i++)
    {
        output+=to_string(result[i]);
    }

    if(str1=="0"||str2=="0")
    {
        output="0";
    }

    fout<<output;

    return 0;
}