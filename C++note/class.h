#ifndef CLASS_H //避免重复定义
#define CLASS_H
#include <iostream>

class MyClass {
public:
    MyClass(int x) : m_x(x) {}
    void printX() const { std::cout << "X: " << m_x << std::endl; }

private:
    int m_x;
};

#endif // CLASS_H
