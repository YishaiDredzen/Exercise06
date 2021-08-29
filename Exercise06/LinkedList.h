#ifndef _LinledList_H_
#define _LinkedList_H_
#include <stddef.h>

typedef int ListDataType;

typedef struct Node_t
{
    ListDataType data;
    struct Node_t *previous;
    struct Node_t *next;
} Node;

typedef struct List_t
{
    Node *head;
} List;

// 1: Called a function with NULL pointer
// 2: Out of memory
int GetLastLinkedErrorList(void);

/**
 * @brief  Creates a linked list
 * @return An empty list with a NULL head
*/
List *CreateList(void);

/**
 * @brief Clears the memory of each node and the list
 * @param list - the list to be cleared from memory
*/
void FreeList(List *list);

/**
 * @brief Computes the number of nodes in a given linked list.
 * @param list - the linked list
 * @return the number of nodes in the list
*/
size_t GetListSize(List *list);

/**
 * @brief Returns a pointer to the head of a list
 * @param list - a linked list
 * @return pointer to the head of the given list
*/
Node *GetListHead(List *list);

/**
 * @brief Returns the next node following a given node
 * @param currentNode - a node
 * @return the next node in the list
*/
Node *GetNextNode(Node *currentNode);

/**
 * @brief Computes the value stored in a node
 * @param node 
 * @return the value stored in a node
*/
ListDataType GetValue(Node *node);

/**
 * @brief Inserts a node after a given node in a linked list
 * @param after - the node where the node should be inserted after
 * @param newValue - the value to be stored in the new node
 * @return the new node
*/
Node *Insert(Node *after, ListDataType newValue);   //Incomplete...

/**
 * @brief Inserts a node at the head of the linked list
 * @param list - linked list 
 * @param newValue - value for the new head
 * @return the new head node
*/
Node *PushFront(List *list, ListDataType newValue);

/**
 * @brief Appends a node to the end of the linked list
 * @param list - linked list
 * @param newValue - the value for the new node
 * @return the new node
*/
Node *PushBack(List *list, ListDataType newValue);

/**
 * @brief Pops the head of the list
 * @param list - linked list
 * @return the value stored in the head.
*/
ListDataType PopFront(List *list);

/**
 * @brief Pops the value from the end of the linked list.
 * @param list - linked list
 * @return the value stored in the  last node
*/
ListDataType PopBack(List *list);

/**
 * @brief Deletes a node from a linked list given a pointer to the node
 * @param list - linked list
 * @param target - pointer to the node to be deleted
*/
void DeleteNode(List *list, Node *target);

/**
 * @brief Finds and deletes the first node with a given value
 * @param list - linked list
 * @param value - the value to be found and the node deleted
 * @return the node preceding the one that contained the value
*/
Node *DeleteValue(List *list, ListDataType value);

/**
 * @brief Searches for a node with a given value
 * @param list - linked list
 * @param value - the value to be searched for
 * @return the node with the given value
*/
Node *Find(List *list, ListDataType value);

#endif
