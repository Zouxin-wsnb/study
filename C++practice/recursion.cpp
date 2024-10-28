#include"main.hpp"

int get_total(int n)
{
    if(n==1)return 1;
    int total = 1; // 当前层的计数
    int next = n / 2;
    for (int i = 1; i <= next; i++) {
        total += get_total(i); // 递归调用并累加结果
    }
    return total;
}

int main()
{
    int input;cin>>input;
    cout<<get_total(input);
}