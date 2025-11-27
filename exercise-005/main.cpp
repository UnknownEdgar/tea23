#include <fmt/chrono.h>
#include <fmt/format.h>
#include "list.hpp"

auto main(int argc, char** argv) -> int
{
    fmt::print("Hello, {}!\n", argv[0]);

    List_t* myList = NewList();

    for (unsigned int i = 1; i <= 5; ++i) {
        ListNode_t* newNode = NewListNode();
        newNode->data = i * 10;
        InsertIntoLinkedList(myList, newNode);
    }

    fmt::print("Initial list:\n");
    PrintList(myList);

    ListNode_t* secondNode = myList->pHead->pNext;
    ListNode_t* insertedNode = NewListNode();
    insertedNode->data = 25;
    InsertIntoLinkedListAfterNode(myList, secondNode, insertedNode);

    fmt::print("After inserting 25 after second node:\n");
    PrintList(myList);

    RemoveFromList(myList, secondNode);
    FreeListNode(secondNode);
    
    fmt::print("After removing the second node:\n");
    PrintList(myList);

    FreeList(myList);
    return 0;
}
