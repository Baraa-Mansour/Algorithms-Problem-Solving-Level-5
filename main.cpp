#include <iostream>
#include "DS/DoubleLinkedList.h"
#include "DS/Queue.h"
#include "DS/Stack.h"
using namespace std;

void TryDoubleLinkedList();
void TryQueue();
void TryStack();

int main()
{
    TryQueue();
    TryStack();
}

void TryStack()
{
    Stack<int> stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    stack.Print();
    cout << "Size: " << stack.Size() << endl;
    cout << "Top: " << stack.Top() << endl;
    cout << "Bootom: " << stack.Bootom() << endl;

    cout << "Pop: " << stack.Pop() << endl;
    stack.Print();
}
void TryQueue()
{
    Queue<int> queue;

    queue.Push(10);
    queue.Push(20);
    queue.Push(30);
    queue.Push(40);
    queue.Push(50);

    queue.Print();
    cout << "Size: " << queue.Size() << endl;
    cout << "Front: " << queue.Front() << endl;
    cout << "Back: " << queue.Back() << endl;

    cout << "Pop: " << queue.Pop() << endl;
    queue.Print();
}
void TryDoubleLinkedList()
{
    DoubleLinkedList<int> doubleLinkedList;

    doubleLinkedList.DeleteLastnode();
    doubleLinkedList.Delete(25);
    doubleLinkedList.DeleteFirstNode();

    doubleLinkedList.InsertAtEnd(8);
    doubleLinkedList.DeleteLastnode();

    doubleLinkedList.InsertAtEnd(7);
    doubleLinkedList.Delete(25);

    doubleLinkedList.InsertAtBeginning(4);
    doubleLinkedList.InsertAtBeginning(3);
    doubleLinkedList.InsertAtBeginning(2);
    doubleLinkedList.InsertAtBeginning(1);

    doubleLinkedList.InsertAfterValue(2, 25);
    doubleLinkedList.InsertAfterValue(4, 5);
    doubleLinkedList.InsertAfterValue(9, 10);
    doubleLinkedList.InsertAfterValue(1, 15);

    doubleLinkedList.InsertAtEnd(9);

    doubleLinkedList.Delete(25);
    doubleLinkedList.Delete(15);
    doubleLinkedList.Delete(9);
    doubleLinkedList.DeleteFirstNode();
    doubleLinkedList.DeleteLastnode();

    doubleLinkedList.Print();
    doubleLinkedList.Reverse();
    doubleLinkedList.Print();

    if (doubleLinkedList.UpdateValue(3, 1))
        doubleLinkedList.Print();

    doubleLinkedList.InsertAfterIndex(2, 2);
    doubleLinkedList.Print();


    DoubleLinkedList<int>::Node* DoubleNode = doubleLinkedList.Find(3);
    if (DoubleNode != NULL)
        cout << "Found By Value: " << DoubleNode->Value << endl;
    else
        cout << "Not Found!" << endl;

    DoubleLinkedList<int>::Node* DoubleNode2 = doubleLinkedList.GetNode(2);
    if (DoubleNode2 != NULL)
        cout << "Found By Index: " << DoubleNode2->Value << endl;
    else
        cout << "Not Found!" << endl;

    int Value = doubleLinkedList.GetValue(0);
    if (Value != NULL)
        cout << "Found By Index: " << Value << endl;
    else
        cout << "Not Found!" << endl;

    cout << "Size: " << doubleLinkedList.Size << endl;

    if (doubleLinkedList.IsEmpty())
        cout << "Empty!" << endl;
    else
        cout << "Not Empty!" << endl;

    doubleLinkedList.Clear();
    if (doubleLinkedList.IsEmpty())
        cout << "Empty After Clear!" << endl;
    else
        cout << "Not Empty, Problem With Clear!" << endl;
}