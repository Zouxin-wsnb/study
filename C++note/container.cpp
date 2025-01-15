#include<iostream>
// Sequential Containers
#include<vector>
#include<list>
#include<array>
#include<deque>
#include<forward_list>
#include<string>
#include<stack>
#include<queue>
//Associative Containers
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
//Generic Algorithm
#include<algorithm>

using namespace std;

// Rules of thumb
// • Use vector by default
// • Don’t use list / forward_list if you have lots of small elements and space overhead matters (pointers take space)
// • Requires random access: vector / deque
// • Add/delete elements in the middle: list / forward_list
// • Add/delete elements at the front and the back: deque
// • Add elements in the middle of the container when reading data
  //  Decide whether you actually need to add elements (or maybe sort after reading all data)
  //  If you must elements in the middle, first use list then copy to a vector


// Operations Supported by All Container Types
// • Iterators
  // vec.begin(), vec.end(), vec.cbegin(), vec.cend()
  // vec.rbegin(), vec.rend(), vec.crbegin(), vec.crend()
// • Construction
  // vector<int> vec;
  // vector<int> vec(5);
  // vector<int> vec(5, 3); // only for sequential
  // vector<int> vec{1, 2, 3};
  //  vec.size(), vec.empty()
// • Assignment and Swap
// • Relational Operators
// • Modification
  //  vec.insert(iter, 5);
  //  vec.emplace(iter, 1);
  //  vec.erase(iter);
  //  vec.clear();

// Lambda Expression
// [capture-clause] (parameters) -> return_type {
//  // function body
// }
  // []捕获列表（capture-clause）
  // ()参数列表（parameters）
  // ->返回类型（return_type）
  // {}函数体（function body）

int main()
{
    int myints[2][5]={{1,2,3,4,5},{6,7,8,9,10}};

    vector<int> new1 = {8,5,3,8,2,3};
    sort(new1.begin(), new1.end());
    for (auto i : new1)
    {
        cout << i << " ";
    }
    cout << '\n';

    vector<int> vec = {1, 2, 3, 4, 5};
    deque<double> deq;
    deq.assign(vec.begin(), vec.end());

    vector<int> vec2 = {1, 2, 3, 4};
    vec.swap(vec2);
    cout << "vec: ";
    for (auto i : vec)
    {
        cout << i << " ";
    }

    vector<int> vec3 = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vec3.begin(); 
    while (iter != vec3.end()) {
    if (*iter % 2) {
        iter = vec3.insert(iter, *iter);
        iter += 2;
    }
    else
    iter = vec3.erase(iter);
    }
    cout << "vec3: ";
    for (auto i : vec3)
    {
        cout << i << " ";
    }

    queue<int> q;
q.push(3);
q.push(5);
cout<<'\n';
cout << q.size() << ' ' << q.front() << ' ' << q.back() << '\n';
q.pop();
cout << q.size() << ' ' << q.front() << ' ' << q.back() << '\n';
}

/*  
1. vector（向量）
- `push_back()` - 在末尾添加元素
- `pop_back()` - 删除末尾元素
- `capacity()` - 返回当前分配的存储空间大小
- `reserve()` - 预分配存储空间
- `resize()` - 改变容器中元素数量
- `shrink_to_fit()` - 释放未使用的内存

2. list（双向链表）
- `push_front()`, `push_back()` - 在首/尾添加元素
- `pop_front()`, `pop_back()` - 删除首/尾元素
- `splice()` - 将一个list的元素插入到另一个list
- `merge()` - 合并两个有序链表
- `reverse()` - 反转链表
- `sort()` - 对链表进行排序
- `unique()` - 删除连续重复元素

3. deque（双端队列）
- `push_front()`, `push_back()` - 在首/尾添加元素
- `pop_front()`, `pop_back()` - 删除首/尾元素
- `at()` - 访问指定位置元素（带边界检查）

4. set/multiset（集合/多重集合）
- `insert()` - 插入元素
- `erase()` - 删除元素
- `find()` - 查找元素
- `count()` - 统计某个值的个数
- `lower_bound()` - 返回第一个不小于给定值的迭代器
- `upper_bound()` - 返回第一个大于给定值的迭代器

5. map/multimap（映射/多重映射）
- `insert()` - 插入键值对
- `operator[]` - 访问或插入元素（仅map支持）
- `find()` - 查找键
- `count()` - 统计某个键的个数
- `equal_range()` - 返回相等元素的范围

6. stack（栈）
- `push()` - 入栈
- `pop()` - 出栈
- `top()` - 访问栈顶元素

7. queue（队列）
- `push()` - 入队
- `pop()` - 出队
- `front()` - 访问队首元素
- `back()` - 访问队尾元素

8. priority_queue（优先队列）
- `push()` - 插入元素
- `pop()` - 删除最高优先级元素
- `top()` - 访问最高优先级元素

9. forward_list（单向链表）
- `push_front()` - 在首部添加元素
- `pop_front()` - 删除首部元素
- `insert_after()` - 在指定位置之后插入
- `erase_after()` - 删除指定位置之后的元素
*/