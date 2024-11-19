#include <iostream>
using namespace std;

// 模板函数
template <typename T> // 声明模板，typename 可以换成 class(两者意思相同)
struct Node {
    T data;
    Node *next;
};

template <typename T>
class singleList {
public:
    Node<T> *head; // 头指针,数据类型为data
    singleList() {
        head = new Node<T>;
        head->next = nullptr;
    }
    ~singleList() {
        Node<T> *p = head;
        while (p != nullptr) {
            Node<T> *q = p;
            p = p->next;
            delete q;
        }
    }
};

template <typename T>
T add(T a, T b) {
    return a + b;
}

template<class Iter>  // 迭代器模板
void print_container(Iter begin, Iter end) {
    for (auto iter = begin; iter != end; ++iter) {
    cout << *iter << ", ";
}
cout << '\n';
}
template<class T>
void print(const T& container) {
    print_container(container.begin(), container.end());
}

int main() {
    cout << add(3, 5) << endl;       // 输出：8（整型）
    cout << add(2.5, 3.5) << endl;  // 输出：6（浮点型）
    return 0;
}
