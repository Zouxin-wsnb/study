#include<iostream>
#include<vector>
#include<sstream>
#include<memory>
using namespace std;

vector<vector<int>> all;

void get_all(const vector<int>& input, int begin_index, int end_index)
{
    vector<int> temp=input;
    if(begin_index==end_index)
    {
        all.push_back(temp);
        return;
    }
    for(int i=begin_index;i<=end_index;i++)
    {
        swap(temp[begin_index],temp[i]);
        get_all(temp,begin_index+1,end_index);
        swap(temp[begin_index],temp[i]);
    }
}

void get_all_exe(vector<int> input)
{
    int begin_index = 0;
    int end_index = input.size()-1;
    get_all(input, begin_index, end_index);
}

class A {
public:
A() {cout << "A's ctor.\n";}
virtual ~A() {cout << "A's dtor.\n";}
};
class B : public A {
public:
B() {cout << "B's ctor.\n";}
virtual ~B() {cout << "B's dtor.\n";}
};

int main()
{
    // vector<int> input;
    // int temp;
    // string line;
    // getline(cin, line);
    // istringstream iss(line);
    // while (iss >> temp)
    // {
    //     input.push_back(temp);
    // }
    // get_all_exe(input);
    // for(auto i:all)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // std::string str ("Replace the vowels by asterisks.");
    // std::size_t found = str.find_first_of("aeiou");
    // while (found!=std::string::npos) {
    //     str[found]='*';
    //     found=str.find_first_of("aeiou",found+1);
    // }
    // std::cout << str << '\n';

    unique_ptr<A> a_ptr = make_unique<A>();
    unique_ptr<A> b_ptr = make_unique<B>();

}