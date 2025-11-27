#include <iostream>
#include <fmt/format.h>
#include "list.hpp"

ListNode_t* NewListNode(void)
{
    ListNode_t* node = new ListNode_t;
    node->data = 0;
    node->pNext = NULL;
    return node;
}

void FreeListNode(ListNode_t* elem)
{
    delete elem;
}

List_t* NewList(void)
{
    List_t* list = new List_t;
    list->pHead = NULL;
    list->pTail = NULL;
    list->size = 0;
    return list;
}

void FreeList(List_t* list)
{
    ListNode_t* current = list->pHead;
    while (current != NULL) {
        ListNode_t* next = current->pNext;
        FreeListNode(current);
        current = next;
    }
    delete list;
}

int InsertIntoLinkedList(List_t* list, ListNode_t* elem)
{
    if (list->pHead == NULL) {
        list->pHead = elem;
        list->pTail = elem;
    } else {
        list->pTail->pNext = elem;
        list->pTail = elem;
    }
    list->size++;
    return 0; // success
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem)
{
    if (node == NULL) {
        return -1; // error: node is NULL
    }
    elem->pNext = node->pNext;
    node->pNext = elem;
    if (node == list->pTail) {
        list->pTail = elem;
    }
    list->size++;
    return 0; // success
}

int RemoveFromList(List_t* list, ListNode_t* elem)
{
    if (list->pHead == NULL || elem == NULL) {
        return -1; // error: list is empty or elem is NULL
    }

    if (list->pHead == elem) {
        list->pHead = elem->pNext;
        if (list->pTail == elem) {
            list->pTail = NULL;
        }
        list->size--;
        return 0; // success
    }

    ListNode_t* current = list->pHead;
    while (current != NULL && current->pNext != elem) {
        current = current->pNext;
    }

    if (current == NULL) {
        return -1; // error: elem not found
    }

    current->pNext = elem->pNext;
    if (list->pTail == elem) {
        list->pTail = current;
    }
    list->size--;
    return 0; // success
}

ListNode_t* GetNext(const List_t* list, ListNode_t* elem)
{
    if (elem == NULL) {
        return NULL;
    }
    return elem->pNext;
}

void PrintList(const List_t* list)
{
    ListNode_t* current = list->pHead;
    while (current != NULL) {
        fmt::print("{} -> ", current->data);
        current = current->pNext;
    }
    fmt::print("NULL\n");
}