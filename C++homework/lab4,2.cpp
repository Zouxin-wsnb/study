#include <iostream>
using namespace std;

int getgcd(int num1,int num2)
{
    while(num2!=0)
    {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int main()
{
    int num1,num2;cin >> num1 >> num2;
    int gcd;
    if(num1==num2)
    {
        gcd = num1;
    }
    else if(num1>num2)
    {
        gcd=getgcd(num1,num2);
    }
    else
    {
        gcd=getgcd(num2,num1);
    }
    cout<<gcd;
}