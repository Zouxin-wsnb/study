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