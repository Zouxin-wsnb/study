#include<iostream>
#include <string>
using namespace std;

string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                  "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty",
                 "sixty", "seventy", "eighty", "ninety"};
string thousands[] = {"", "thousand", "million", "billion"};

string three_digit(string num)
{
    if(num == "" || num == "000") return "";
    while(num.size() < 3) {
        num = "0" + num; //补齐三位
    }

    string result;
    int hundred = num[0] - '0';
    int ten = num[1] - '0';
    int one = num[2] - '0';

    if(hundred > 0) 
    {
        result += ones[hundred] + " hundred";
    }

    if(ten == 1) 
    {
        if(!result.empty()) result += " ";
        result += teens[one]; //10-19
    } 
    else 
    {
        if(ten > 1) //20-99
        {
            if(!result.empty()) result += " ";
            result += tens[ten];
            if(one > 0) 
            {
                result += "-" + ones[one];
            }
        } 
        else if(one > 0) //1-9
        {
            if(!result.empty()) result += " ";
            result += ones[one];
        }
    }

    return result;
}

int main()
{
    string num;cin>>num;
    if(num=="0"){cout<<"zero";return 0;}
    string single="",thousand="",million="",billion="",negetive="";
    if(num[0]=='-')
    {
        negetive="negative ";
        num=num.substr(1,num.size()-1);
    }
    if(num.size()<4)
    {
        single=num;
    }
    else if(num.size()<7)
    {
        single=num.substr(num.size()-3,3);
        thousand=num.substr(0,num.size()-3);
    }
    else if(num.size()<10)
    {
        single=num.substr(num.size()-3,3);
        thousand=num.substr(num.size()-6,3);
        million=num.substr(0,num.size()-6);
    }
    else
    {
        single=num.substr(num.size()-3,3);
        thousand=num.substr(num.size()-6,3);
        million=num.substr(num.size()-9,3);
        billion=num.substr(0,num.size()-9);
    } //分割数字
    string res_billion=three_digit(billion);
    string res_million=three_digit(million);
    string res_thousand=three_digit(thousand);
    string res_single=three_digit(single);
    if(res_billion!="")res_billion+=" billion ";
    if(res_million!="")res_million+=" million ";
    if(res_thousand!="")res_thousand+=" thousand ";
    cout<<negetive<<res_billion<<res_million<<res_thousand<<res_single;
}