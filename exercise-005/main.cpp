#include <fmt/chrono.h>
#include <fmt/format.h>
#include <chrono>
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

    // ========== OPTIONAL: PERFORMANCE TESTING ==========
    fmt::print("\n=== PERFORMANCE COMPARISON (Insert at position 1) ===\n");

    const int NUM_INSERTS = 10000;

    // Test Vector insert_at
    Vector_t perfVector;
    vector_init(&perfVector);
    
    auto vectorStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_INSERTS; ++i) {
        vector_insert_at(&perfVector, 0, i);  // Insert at beginning
    }
    auto vectorEnd = std::chrono::high_resolution_clock::now();
    auto vectorDuration = std::chrono::duration_cast<std::chrono::microseconds>(vectorEnd - vectorStart);

    fmt::print("Vector insert_at (at position 0) {} times: {}µs\n", NUM_INSERTS, vectorDuration.count());
    vector_clear(&perfVector);

    // Test List insert (at beginning)
    List_t* perfList = NewList();
    
    auto listStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_INSERTS; ++i) {
        ListNode_t* node = NewListNode();
        node->data = i;
        // For fairness, we insert after the first node if list is not empty
        if (perfList->pHead != nullptr) {
            InsertIntoLinkedListAfterNode(perfList, perfList->pHead, node);
        } else {
            InsertIntoLinkedList(perfList, node);
        }
    }
    auto listEnd = std::chrono::high_resolution_clock::now();
    auto listDuration = std::chrono::duration_cast<std::chrono::microseconds>(listEnd - listStart);

    fmt::print("List insert_after (after first node) {} times: {}µs\n", NUM_INSERTS, listDuration.count());
    FreeList(perfList);

    fmt::print("\nConclusion:\n");
    if (vectorDuration.count() < listDuration.count()) {
        fmt::print("  Vector is faster for this operation\n");
    } else {
        fmt::print("  List is faster for this operation\n");
    }

    myVector.data = nullptr;  // Already cleared, just set to nullptr
    return 0;
}
