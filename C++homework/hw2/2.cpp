#include<iostream>
#include <string>
#include<sstream>
#include <unordered_map>
using namespace std;

unordered_map<string, long long> number_map = {
    {"zero", 0},
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
    {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
    {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
    {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}
};

string str_to_int(string str)
{
    int result[2]={0,0};
    if(str==""){return "000";}
    if(str.find("hundred")!=string::npos)
    {
        result[0]=number_map[str.substr(0,str.find("hundred")-1)];
        str=str.substr(str.find("hundred")+8);
    }
    if(str.find("-")!=string::npos)
    {
        result[1]=number_map[str.substr(0,str.find("-"))];
        str=str.substr(str.find("-")+1);
        result[1]+=number_map[str];
    }
    else
    {
        result[1]=number_map[str];
    }
    string res=to_string(result[0]*100+result[1]);
    while(res.size()<3)
    {
        res="0"+res;
    }
    return res;
}

int main()
{
    string input;
    getline(cin, input);
    if (input == "zero") { cout << 0; return 0; }
    
    string total = "";
    bool isNegative = false;

    //处理负数
    if (input.find("negative") != string::npos)
    {
        input = input.substr(9);
        isNegative = true;
    }
    

    //提取 billion, million, thousand和剩余部分
    string billion = "", million = "", thousand = "", single = "";
    string billion_str = "000", million_str = "000", thousand_str = "000", single_str = "000";
    if (input.find("billion") != string::npos)
    {
        billion = input.substr(0, input.find("billion") - 1);
        input = input.substr(input.find("billion") + 8);
        billion_str = str_to_int(billion);
    }
    if (input.find("million") != string::npos)
    {
        million = input.substr(0, input.find("million") - 1);
        input = input.substr(input.find("million") + 8);
        million_str = str_to_int(million);
    }
    if (input.find("thousand") != string::npos)
    {
        thousand = input.substr(0, input.find("thousand") - 1);
        input = input.substr(input.find("thousand") + 9);
        thousand_str = str_to_int(thousand);
    }
    single = input;
    single_str = str_to_int(single);

    //合并
    total = billion_str + million_str + thousand_str + single_str;

    while(total[0]=='0') //去掉0
    {
        total=total.substr(1);
    }

    //输出
    if (isNegative) cout << "-";
    cout << total;

    return 0;
}