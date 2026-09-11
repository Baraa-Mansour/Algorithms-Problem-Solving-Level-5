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

    DoubleLinkedList<int>::Node* DoubleNode = doubleLinkedList.Find(3);
    if (DoubleNode != NULL)
        cout << "Found: " << DoubleNode->Value << endl;
    else
        cout << "Not Found!" << endl;
}
