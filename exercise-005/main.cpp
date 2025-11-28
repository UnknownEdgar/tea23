#include <fmt/chrono.h>
#include <fmt/format.h>
#include "list.hpp"
#include "vector.hpp"

auto main(int argc, char** argv) -> int
{
    fmt::print("Hello, {}!\n", argv[0]);

    // ========== LINKED LIST TESTING ==========
    fmt::print("\n=== LINKED LIST ===\n");
    
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

    // ========== VECTOR TESTING ==========
    fmt::print("\n=== VECTOR ===\n");
    
    Vector_t myVector;
    vector_init(&myVector);

    for (unsigned int i = 1; i <= 5; ++i) {
        vector_push_back(&myVector, i * 10);
    }

    fmt::print("Initial vector:\n");
    vector_print(&myVector);

    vector_push_back(&myVector, 25);
    fmt::print("After pushing 25:\n");
    vector_print(&myVector);

    unsigned int value;
    vector_get(&myVector, 2, &value);
    fmt::print("Element at index 2: {}\n", value);

    fmt::print("Vector size: {}, capacity: {}\n", myVector.size, myVector.capacity);

    vector_clear(&myVector);
    fmt::print("After clearing:\n");
    vector_print(&myVector);

    return 0;
}
