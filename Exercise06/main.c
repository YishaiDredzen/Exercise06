#include <stdlib.h>

#include "LinkedList.h"

int main(void)
{
    List *list = CreateList();
    list->head = PushFront(list, 5);
    Node *nextNode = list->head;
    nextNode = Insert(nextNode, 6);
    nextNode = Insert(nextNode, 7);
    nextNode = Insert(nextNode, 8);
    nextNode = Find(list, 6);
    nextNode = Insert(nextNode, 10);
    int data = GetValue(nextNode);
    Node *deleteNode = DeleteValue(list, data);
    Node *deleteNodeptr = deleteNode->previous;
    DeleteNode(list, deleteNodeptr);
    PushFront(list, 89);
    data = PopBack(list);
    data = PopFront(list);
    FreeList(list);
    return 0;
}