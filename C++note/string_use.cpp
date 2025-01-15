#include<iostream>
#include <string>
using namespace std;

size_t find(const string &src,const string &pattern, int start)
{
    if(start<0||start>=src.size())
        return string::npos;
    for(size_t i=start;i<src.size();++i)
    {
        if(src[i]==pattern[0])
        {
            size_t j=0;
            for(;j<pattern.size();++j)
            {
                if(src[i+j]!=pattern[j])
                    break;
            }
            if(j==pattern.size())
                return i;
        }
    }
    return string::npos;
}

int main()
{
    string example = "Hello, World!";
    cout << example[1] << endl;
    string example2 = R"(
Hello, World!
This is a new line.)";
    cout << example2 << endl;
    // 提取从索引 7 开始的子字符串
    string sub1 = example.substr(7);
    cout << sub1 << endl;  // 输出: World!

    // 提取从索引 0 开始，长度为 5 的子字符串
    string sub2 = example.substr(0, 5);
    cout << sub2 << endl;  // 输出: Hello

    string example3;
    cout << "Enter a line of text: ";
    // getline(cin, example3);
    // cout << "You entered: " << example3 << endl;

    string fname = "Harry";
    string lname = "Potter";
    string name = fname + " " + lname;
    //string name2 = "Harry" + "Hacker";  不能直接将两个字符串字面量相加。
    string name3 = "Harry" + lname;
    cout << name << name3 <<endl;

    int compare = fname.compare(lname);
    if(compare == 0)
        cout << "Strings are equal" << endl;
    else if(compare < 0)
        cout << "First string is less than second" << endl;
    else
        cout << "First string is greater than second" << endl;

    // 使用 .find() 查找子字符串，如果找不到子字符串，则返回 std::string::npos。
    size_t pos = example.find("World");
    if (pos != string::npos) {
        cout << "\"World\" found at position: " << pos << endl;
    } else {
        cout << "\"World\" not found" << endl;
    }
    // 使用 .find_first_of() 查找字符集合中的任意一个字符
    string charset = "aeiou";
    pos = example.find_first_of(charset);
    if (pos != string::npos) {
        cout << "First vowel found at position: " << pos << endl;
    } else {
        cout << "No vowels found" << endl;
    }

     // 使用 std::string_view，这是一个指针和长度的轻量级包装器。
    string_view sv = example;
    cout << "String view: " << sv << endl;
}