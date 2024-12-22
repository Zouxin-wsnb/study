#include "class.h"
#include <vector>
using namespace std;

// 4 Pillars of OOP:
// 1. Encapsulation-封装
// 核心思想：将数据和操作数据的代码封装在一起，隐藏内部实现细节，通过公共接口与外部交互。
// 2. Abstraction-抽象
// 核心思想：通过抽象类和接口，提供抽象的概念和行为，隐藏具体实现细节。
// 3. Inheritance-继承
// 核心思想：通过继承机制，子类可以继承父类的属性和方法，实现代码重用和扩展。
// 4. Polymorphism-多态
// 核心思想：通过多态机制，子类可以重写父类的方法，实现不同的行为，提供灵活的接口。

// SOLID Principle
// • Single Responsibility Principle 
// 核心思想：一个类应该只有一个改变的理由，即只负责一个功能。
// • Open/Closed Principle
// 核心思想：软件实体应该对扩展开放，对修改关闭。添加新功能时，应该扩展代码，而不是修改现有代码。
// • Liskov’s Substitution Principle
// 核心思想：子类必须能够替换其基类。子类对象能够在程序中替代父类对象使用，而程序行为保持一致。
// • Interface Segregation Principle
// 核心思想：客户端不应该依赖它不需要的接口。大接口应该被拆分成更小的、更具体的接口。
// • Dependency Inversion Principle
// 核心思想：
// 高层模块不应该依赖低层模块，两者都应该依赖抽象
// 抽象不应该依赖细节，细节应该依赖抽象

// Association
// • Two class has some relationships
// Aggregation (has a)
// • A class is a collection or container of other classes 
// • Separate lifetimes
// Composition (has a)
// • *Stronger than aggregation
// • If the container is destroyed, its contents are also destroyed
// Inheritance (is a)

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
