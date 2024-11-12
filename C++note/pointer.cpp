#include<iostream>
using namespace std;

class MyClass {
public:
    MyClass(int x) : m_x(x) {}
    void printX() const { std::cout << "X: " << m_x << std::endl; }
private:
    int m_x;
};

int** create_2D_array(int height, int width) {
    int** array = new int*[height];
    for (int i = 0; i < height; ++i) {
        array[i] = new int[width];
    }
    return array;
}

void delete_2D_array(int** array, int height) {
    for (int i = 0; i < height; ++i) {
        delete[] array[i];
    }
    delete[] array;
}


class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


class SinglyLinkedList {  //单链表
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = new Node(0); // Sentinel node
    }

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteValue(int value) {
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void printList() {
        Node* current = head->next; // Skip sentinel node
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};


int main()
{
    int a = 10;
    int *p = &a;
    cout << "a = " << a << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    
    MyClass *obj= new MyClass(20);
    obj->printX();
    delete obj;  //释放内存

    int** array = create_2D_array(3, 4);
    // Use the array
    delete_2D_array(array, 3);
}