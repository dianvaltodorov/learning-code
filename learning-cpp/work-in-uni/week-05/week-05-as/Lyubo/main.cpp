#include <iostream>

using namespace std;

struct Node {
   Node* next;
   int data;
   Node(int data) {
       this->data = data;
   }
};

struct List {
    Node* start;
    Node* end;
    void append(int data) {
        if (start == NULL) {
            start = new Node(data);
            end = start;
        } else {
            Node* toAppend = new Node(data);
            end->next = toAppend;
            end=toAppend;
        }
    }
    void deleteList()
    {
    }
};


int main()
{
    cout << "Hello World!" << endl;
    List* a = new List();
    a->append(5);
    a->append(4);
    a->append(5);
    a->append(6);
    a->append(7);
    a->append(8);
    a->append(9);
    a->append(0);
    Node* current = a->start;
    while(current) {
        cout<<current->data<<", ";
        current = current->next;
    }

    cout<<endl;
    return 0;
}
