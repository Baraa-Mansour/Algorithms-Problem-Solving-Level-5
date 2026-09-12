#include <iostream>
#include "DS/DoubleLinkedList.h"
using namespace std;

int main()
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

    doubleLinkedList.InsertAfter(2, 25);
    doubleLinkedList.InsertAfter(4, 5);
    doubleLinkedList.InsertAfter(9, 10);
    doubleLinkedList.InsertAfter(1, 15);

    doubleLinkedList.InsertAtEnd(9);

    doubleLinkedList.Delete(25);
    doubleLinkedList.Delete(15);
    doubleLinkedList.Delete(9);
    doubleLinkedList.DeleteFirstNode();
    doubleLinkedList.DeleteLastnode();

    doubleLinkedList.Print();
    doubleLinkedList.Reverse();
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
