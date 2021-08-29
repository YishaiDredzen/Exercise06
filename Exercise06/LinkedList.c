#include  "LinkedList.h"
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

int g_lastLinkedListError = 0;


List* CreateList(void)
{
    List* list = malloc(sizeof(List));
    if (list)
    {
        list->head = NULL;
        g_lastLinkedListError = 0;
    }
    else
    {
        g_lastLinkedListError = 2;
    }

    return list;
}

void FreeList(List* list)
{
    if (!list)
    {
        g_lastLinkedListError = 1;
    }
    else
    {
        if (list->head)
        {
            Node* current = GetListHead(list);
            while (current)
            {
                Node* next = GetNextNode(current);
                free(current);
                current = next;
            }
        }
    }

    free(list);
}

size_t GetListSize(List* list)
{
    size_t size = 0;
    if (list)
    {
        while (list->head->next)
        {
            ++size;
        }
    }
    return size;
}

Node* GetListHead(List* list)
{
    if (list)
    {
        return list->head;
    }
    return NULL;
}

Node* GetNextNode(Node* currentNode)
{
    if (currentNode)
    {
        return currentNode->next;
    }
    return NULL;
}

ListDataType GetValue(Node* node)
{
    if (node)
    {
        return node->data;
    }
    return 0;
}

Node* Insert(Node* after, ListDataType newValue)
{
    if (after)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = newValue;
        newNode->next = after->next;
        after->next = newNode;
        newNode->previous = after;
        return newNode;
    }
    return NULL;
}

Node* PushFront(List* list, ListDataType newValue)
{
   
    if (list)
    {
        if (GetListHead(list)) {
            Node *newNode = malloc(sizeof(Node));
            list->head->previous = newNode;
            newNode->next = GetListHead(list);
            list->head = newNode;
            newNode->data = newValue;
        }
        else
        {
            list->head = (Node *)malloc(sizeof(Node));
            GetListHead(list)->next = NULL;
            GetListHead(list)->previous = NULL;
            GetListHead(list)->data = newValue;
        }
        return list->head;
    }
    return NULL;
}

Node *PushBack(List *list, ListDataType newValue)
{
    
     if (list)
    {
        Node *current = GetListHead(list);
        while (GetNextNode(current) != NULL)
        {
            current = GetNextNode(current);
        }

        Node *newNode = (Node *)malloc(sizeof(Node *));
        current->next = newNode;
        newNode->previous = current;
        newNode->data = newValue;
        newNode->next = NULL;
        return newNode;
    }
    return NULL;
     
}


ListDataType PopFront(List *list)
{
    ListDataType data = 0;
    if (list)
    {
        data = list->head->data;
        list->head = list->head->next;
        list->head->next->previous = NULL;
    }
    return data;
}

ListDataType PopBack(List *list)
{
    ListDataType data = 0;
    if (list)
    {
        Node *currentNode = list->head;
        while (currentNode->next != NULL)
        {
            currentNode = GetNextNode(currentNode);
        }
        data = currentNode->data;
    }
    return data;
}

void DeleteNode(List *list, Node *target)
{
    if (!list || !target)
    {
        g_lastLinkedListError = 1;
        return;
    }
    if (list->head == target)
    {
        assert(target->previous == NULL);
        list->head = target->next;
        target->next->previous = NULL;
    }
    else if (target->next == NULL)
    {
        target->previous->next = NULL;
    }
    else
    {
        target->previous->next = target->next;
        target->next->previous = target->previous;
    }
    free(target);
}

Node *DeleteValue(List *list, ListDataType value)
{
    Node *deleteNode = NULL;
    if (list)
    {
        deleteNode = Find(list, value);
        if (deleteNode)
        {
            deleteNode = deleteNode->previous;
            DeleteNode(list, deleteNode->next);
        }
    }
    return deleteNode;

}

Node *Find(List *list, ListDataType value)
{
    Node *currentNode = NULL;
    if (list)
    {
        currentNode = GetListHead(list);
        while (GetValue(currentNode) != value)
        {
            currentNode = GetNextNode(currentNode);
        }
    }
    return currentNode;
}