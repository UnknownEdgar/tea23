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
    
    // 1. Vector initialisieren
    Vector_t myVector;
    vector_init(&myVector);
    fmt::print("Vector initialized with capacity: {}\n\n", myVector.capacity);

    // 2. Fünf Werte einfügen
    fmt::print("Inserting 5 values:\n");
    for (unsigned int i = 1; i <= 5; ++i) {
        vector_push_back(&myVector, i * 10);
    }
    fmt::print("Vector after inserting 5 values: ");
    vector_print(&myVector);

    // 3. Element an Index 2 ausgeben
    unsigned int value;
    int result = vector_get(&myVector, 2, &value);
    if (result == 0) {
        fmt::print("Element at index 2: {}\n", value);
    } else {
        fmt::print("Error: Index out of bounds\n");
    }

    // 4. Vector ausgeben
    fmt::print("Final vector state:\n");
    fmt::print("  Size: {}\n", myVector.size);
    fmt::print("  Capacity: {}\n", myVector.capacity);
    fmt::print("  Contents: ");
    vector_print(&myVector);

    vector_clear(&myVector);

    return 0;
}
