#include<fstream>
#include<iostream>
#include<string>
using namespace std;

/*
ios::in：打开文件进行输入（读取）操作。
ios::out：打开文件进行输出（写入）操作。
ios::binary：以二进制模式打开文件。
ios::ate：在文件末尾设置初始位置。如果未设置此标志，初始位置是文件的开头。
ios::app：所有输出操作都在文件末尾进行，追加内容到文件的现有内容。
ios::trunc：如果文件已存在且打开进行输出操作，其先前内容将被删除并替换为新内容。
*/
int main()
{
    string filename = "example.txt";
    ofstream file(filename, ios::out | ios::trunc);
        if (file.is_open()) {
            file << "覆盖内容：这是文件的第一行。\n";
            file << "覆盖内容：这是文件的第二行。\n";
            file.close();
        } else {
            std::cerr << "无法打开文件进行写入操作。\n";
        }

    ifstream MyReadFile("example.txt");
    if (!MyReadFile.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string myText;
    while (getline(MyReadFile, myText)) {
        cout << myText << endl;  // 添加换行符
    }
    MyReadFile.close();  // 关闭文件

    ifstream MyReadFile1("D:/mystudy/study/ics note.txt"); //从其他路径读取文件
    string myText1;
    getline(MyReadFile1, myText1);
    cout << myText1 << endl;  // 添加换行符
    MyReadFile1.close();  // 关闭文件
    
}

/*
以下是一些常用的文件模式组合及其作用：

"r" (ios::in)
已存在文件：从文件开头读取内容。
文件不存在：打开失败。

"w" (ios::out | ios::trunc)
已存在文件：清空文件内容。
文件不存在：创建新文件并写入。

"a" (ios::out | ios::app)
已存在文件：所有写入操作添加到文件末尾。
文件不存在：创建新文件。

"r+" (ios::in | ios::out)
已存在文件：从文件开头读取和写入。
文件不存在：打开失败。

"w+" (ios::in | ios::out | ios::trunc)
已存在文件：清空文件并进行读写操作。
文件不存在：创建新文件并进行读写。

"a+" (ios::in | ios::out | ios::app)
已存在文件：读取文件内容，所有写入操作添加到文件末尾。
文件不存在：创建新文件并进行读写。

二进制模式（例如 "rb", "wb", "ab"）
二进制模式用于以二进制格式读取或写入文件，而不是文本格式。这对于保存非文本数据（如图片、视频等）很有用。

特殊模式（例如 "wx", "wbx"）
这些模式允许在文件不存在时创建新文件，但如果文件已存在则打开失败。自C++23起支持ios::noreplace，例如用于确保文件不被意外覆盖。
*/