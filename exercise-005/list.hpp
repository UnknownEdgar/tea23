#ifndef LIST_HPP
#define LIST_HPP

typedef struct ListNode {
    int data;
    struct ListNode* pNext;
} ListNode_t;

typedef struct List {
    ListNode_t* pHead;
    ListNode_t* pTail;
    unsigned int size;
} List_t;

// Function declarations
ListNode_t* NewListNode(void);
void FreeListNode(ListNode_t* elem);
List_t* NewList(void);
void FreeList(List_t* list);
int InsertIntoLinkedList(List_t* list, ListNode_t* elem);
int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem);
int RemoveFromList(List_t* list, ListNode_t* elem);
ListNode_t* GetNext(const List_t* list, ListNode_t* elem);
void PrintList(const List_t* list);  // Make sure this line is present!

#endif