#include "vector.hpp"
#include <fmt/format.h>
#include <cstring>

void vector_init(Vector_t* vec)
{
    vec->capacity = 4;
    vec->size = 0;
    vec->data = new unsigned int[vec->capacity];
}

void vector_clear(Vector_t* vec)
{
    if (vec->data != nullptr) {
        delete[] vec->data;
        vec->data = nullptr;
    }
    vec->size = 0;
    vec->capacity = 0;
}

int vector_push_back(Vector_t* vec, unsigned int value)
{
    if (vec == nullptr) {
        return -1;
    }

    // If capacity exceeded, double it
    if (vec->size >= vec->capacity) {
        size_t newCapacity = vec->capacity * 2;
        unsigned int* newData = new unsigned int[newCapacity];
        
        // Copy existing data
        for (size_t i = 0; i < vec->size; ++i) {
            newData[i] = vec->data[i];
        }
        
        delete[] vec->data;
        vec->data = newData;
        vec->capacity = newCapacity;
    }

    vec->data[vec->size] = value;
    vec->size++;
    return 0; // success
}

int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue)
{
    if (vec == nullptr || outValue == nullptr) {
        return -1;
    }

    if (index >= vec->size) {
        return -1; // out of bounds
    }

    *outValue = vec->data[index];
    return 0; // success
}

int vector_insert_at(Vector_t* vec, size_t index, unsigned int value)
{
    if (vec == nullptr) {
        return -1;
    }

    if (index > vec->size) {
        return -1; // index out of bounds
    }

    // If capacity exceeded, double it
    if (vec->size >= vec->capacity) {
        size_t newCapacity = vec->capacity * 2;
        unsigned int* newData = new unsigned int[newCapacity];
        
        // Copy existing data
        for (size_t i = 0; i < vec->size; ++i) {
            newData[i] = vec->data[i];
        }
        
        delete[] vec->data;
        vec->data = newData;
        vec->capacity = newCapacity;
    }

    // Shift elements to the right
    for (size_t i = vec->size; i > index; --i) {
        vec->data[i] = vec->data[i - 1];
    }

    vec->data[index] = value;
    vec->size++;
    return 0; // success
}

void vector_print(const Vector_t* vec)
{
    if (vec == nullptr || vec->data == nullptr) {
        fmt::print("[empty]\n");
        return;
    }

    fmt::print("[");
    for (size_t i = 0; i < vec->size; ++i) {
        if (i > 0) {
            fmt::print(", ");
        }
        fmt::print("{}", vec->data[i]);
    }
    fmt::print("]\n");
}