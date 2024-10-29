
#include"main.hpp"

int Fibonacci_sum(int num) {
    if (num <= 1) return num;
    int a = 0, b = 1, sum = 0;
    for (int i = 2; i <= num; ++i) {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}
int get_min(int input,int result)
{
    int min=result;
    if(Fibonacci_sum(min)%input==0&&Fibonacci_sum(min+1)%input==1) return min;
    else return get_min(input,min+1);
}


int main()
{
    int input;cin>>input;
    cout<<get_min(input,1);
}