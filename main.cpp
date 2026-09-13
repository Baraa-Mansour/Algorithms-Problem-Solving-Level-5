#include <iostream>
#include "DS/DoubleLinkedList.h"
#include "DS/Queue.h"
#include "DS/Stack.h"
#include "DS/DynamicArray.h"
#include "DS/ArrQueue.h"
#include "DS/ArrStack.h"
#include "String.h"
#include "QueueLine.h"
using namespace std;

void TryDoubleLinkedList();
void TryQueue();
void TryArrQueue();
void TryStack();
void TryDynamicArray();
void TryArrStack();
void StackUseCase();
void QueueUseCase();

int main()
{
    QueueUseCase();
}

void QueueUseCase()
{
    QueueLine PayBillsQueue("A0", 10);
    QueueLine SubscriptionsQueue("B0", 5);

    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    cout << "\nPay Bills Queue Info:\n";
    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();



    PayBillsQueue.PrintAllTickets();

    PayBillsQueue.ServeNextClient();
    cout << "\nPay Bills Queue After Serving One client\n";
    PayBillsQueue.PrintInfo();

    cout << "\nSubscriptions Queue Info:\n";

    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();


    SubscriptionsQueue.PrintInfo();

    SubscriptionsQueue.PrintTicketsLineRTL();
    SubscriptionsQueue.PrintTicketsLineLTR();

    SubscriptionsQueue.PrintAllTickets();

    SubscriptionsQueue.ServeNextClient();
    cout << "\nSubscriptions Queue After Serving One client\n";
    SubscriptionsQueue.PrintInfo();
}
void StackUseCase()
{
    cout << "Undo/Redo Example: \n";
    cout << "==================" << endl;

    String S1;

    cout << "\nS1  = " << S1.Value << "\n";

    S1.Value = "Mohammed";

    cout << "S1  = " << S1.Value << "\n";

    S1.Value = "Mohammed2";

    cout << "S1  = " << S1.Value << "\n";

    S1.Value = "Mohammed3";

    cout << "S1  = " << S1.Value << "\n";

    cout << "\n\nUndo: ";
    cout << "\n__________\n";

    S1.Undo();
    cout << "\nS1  after undo = " << S1.Value << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Value << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Value << "\n";

    cout << "\n\nRedo: ";
    cout << "\n__________\n";

    S1.Redo();
    cout << "\nS1  after Redo = " << S1.Value << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Value << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Value << "\n";


    cout << "\n\nEmpty: ";
    cout << "\n__________\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Value << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Value << "\n";
}
void TryArrStack()
{
    ArrStack<int> stack;

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
void TryArrQueue()
{
    ArrQueue<int> queue;

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
void TryDynamicArray()
{
    DynamicArray<int> arr(5);

    arr.SetItem(0, 1);
    arr.SetItem(1, 3);
    arr.SetItem(2, 5);
    arr.SetItem(3, 7);
    arr.SetItem(4, 9);
    arr.SetItem(5, 9);

    arr.InsertAtBeginning(0);
    arr.InsertAtEnd(10);
    arr.InsertAfter(1, 2);
    arr.InsertBefore(5, 4);

    arr.InsertAt(0, -1);
    arr.InsertAt(6, 5);
    arr.InsertAt(7, 6);

    arr.DeleteItem(2);
    arr.Print();
    cout << "Size: " << arr.Size << endl;
    cout << "Empty: " << arr.IsEmpty() << endl;
    cout << "Find At Index: " << arr.Find(2) << endl;

    arr.DeleteFirstItem();
    arr.DeleteItemAt(2);
    arr.DeleteLastItem();

    arr.Print();
    cout << "Size: " << arr.Size << endl;
    cout << "Empty: " << arr.IsEmpty() << endl;

    arr.Reverse();
    arr.Print();

    arr.ReSize(3);
    arr.SetItem(2, 5);
    arr.Print();
    
    arr.ReSize(2);
    arr.Print();

    arr.Clear();
    arr.Print();
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