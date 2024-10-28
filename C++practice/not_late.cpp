#include"main.hpp"

int main()
{
    int s,v;
    cin>>s>>v;
    int t = s/v;
    if(s%v!=0) t++;
    t+=10;
    int hour=t/60;
    if(hour>8)
    {hour=24-(hour-7);}
    else hour=7-hour;
    int min=60-t%60;
    if(hour<10&&min<10) cout<<"0"<<hour<<":"<<"0"<<min;
    else if(hour<10) cout<<"0"<<hour<<":"<<min;
    else if(min<10) cout<<hour<<":"<<"0"<<min;
    else cout<<hour<<":"<<min;
    return 0;
}