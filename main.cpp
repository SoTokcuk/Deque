#include <iostream>
#include <string>
#include <cstring>
#include "Header.h"
using namespace std;

int main()
{
    char* a = new char[90];
    Deque<const char*> deq;
    cout << "Push back element\n";
    cin >> a;
    deq.pushBack(a);
    cout << "Get back element:";
    deq.getBack();
    cout << endl;
    cout << "Push front element\n";
    cin >> a;
    deq.pushFront(a);
    cout << "Get top element:";
    deq.getTop();
    cout << endl;
    cout << "Get the size of the deque: " << deq.getSize() << "\n";
    cout << "Cout from the end to begin:\n";
    deq.outEnd(cout);
    cout << endl;
    cout << "Cout from begin to end:\n";
    deq.outBegin(cout);
    cout << endl;
    cout << "Pop back element\n" << deq.popBack() << "\n";
    cout << "Pop front element\n" << deq.popFront() << "\n";
    Deque <const char*> deq2;
    deq2 = deq;
    deq2.outBegin(cout);
    return 0;
}
