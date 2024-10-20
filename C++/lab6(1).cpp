#include <iostream>
using namespace std;

int calculate(int money, int price, int num_to_exchange)
{
    int num_bought = money/price;
    int num_free = num_bought/num_to_exchange;
    int num_left = num_bought%num_to_exchange;
    int num_total = num_bought + num_free;
    while(num_free > 0)
    {
        int newfree = (num_free + num_left) / num_to_exchange;
        num_left = (num_free + num_left) % num_to_exchange;
        num_total += newfree;
        num_free = newfree;
    }
    return num_total;
}
int main()
{
    int money,price,num_to_exchange;
    cin>>money>>price>>num_to_exchange;
    int total=calculate(money,price,num_to_exchange);
    cout<<total;
    return 0;
}