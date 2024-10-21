#include "class.h"
#include <vector>
using namespace std;

class example {
public:
    example() { data = new int[10]; }
    ~example() { delete[] data; }
    example(example&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
private:
    int* data;
};

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

ostream& operator<<(ostream& os, const Point& c) {
    os << c.x << " " << c.y;
    return os;
}

class MyClass {
public:
    int* data;
    MyClass(int size) : data(new int[size]) {
        cout << "Constructor called\n";
    }
    ~MyClass() {
        delete[] data;
        cout << "Destructor called\n";
    }
    // 拷贝构造函数
    MyClass(const MyClass& other) : data(new int[*(other.data)]) {
        cout << "Copy constructor called\n";
    }
    // 移动构造函数
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
        cout << "Move constructor called\n";
    }
};

int main() {
    vector<Point> points;
    points.emplace_back(1, 2); // 使用 emplace_back 直接构造 Point 对象
    points.emplace_back(3, 4); // 使用 emplace_back 直接构造 Point 对象
    Point newpoint(666,888);
    points.emplace(points.begin() + 1, newpoint); // 在 vector 1 号位置插入 Point 对象

    for (const auto& point : points) {
        cout << point << endl;
    }

    Point newpoint2=move(newpoint); //用指针类型的参数调用move函数才能真正意义上的移动，这里没做到
    cout << "Moved point: " << newpoint2 << endl;

    return 0;
}
