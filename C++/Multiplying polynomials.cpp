#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> multiply(const vector<int>& a1, const vector<int>& a2)
{
    int x=a1.size();
    int y=a2.size();
    vector<int> result(x+y-1, 0);
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            result[i+j]+=a1[i]*a2[j];
        }
    }
    return result;
}
vector<int> input()
{
    int n;cin>>n;vector<int> total(n+1);
    for(int i=0;i<=n;++i)
    {
        cin>>total[i];
    }
    return total;
}
int main()
{
    vector<int> set1=input();
    vector<int> set2=input();
    vector<int> product=multiply(set1,set2);
    int d=product.size()-1;
    string result;
    for(int i:product)
    {
        if(i==0)continue;
        if(!result.empty()&&i>0)result+="+";
        if(i<0)result+="-";
        if(abs(i)==1&&d!=0)result+="x";
        else if(abs(i)>1&&d!=0)result+=to_string(abs(i))+"x";
        else result+=to_string(abs(i));
        if(d!=0&&d!=1)result+="^"+to_string(d);
        --d;
    }
    cout<<result;
}