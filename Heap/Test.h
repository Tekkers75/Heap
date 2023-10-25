#pragma once
#include <iostream>
#include <cassert>
#include "Heap.h"

void TestConstructor() {
    Heap<int> heap(10);

    assert(heap.IsEmpty());
    assert(heap.Size() == 0);

    std::cout << "Constructor test passed." << std::endl;
}

void TestInsert() {
    Heap<int> heap(5);

    heap.Insert(5);
    heap.Insert(3);
    heap.Insert(7);
    heap.Insert(2);
    heap.Insert(4);

    assert(heap.Size() == 5);
    assert(!heap.IsEmpty());

    std::cout << "Insert test passed." << std::endl;
}

void TestExtractMax() {
    Heap<int> heap(5);

    heap.Insert(5);
    heap.Insert(3);
    heap.Insert(7);
    heap.Insert(2);
    heap.Insert(4);

    int maxElement = heap.ExtractMax();

    assert(maxElement == 7);
    assert(heap.Size() == 4);

    std::cout << "ExtractMax test passed." << std::endl;
}


void TestSize() {
    Heap<int> heap(5);

    assert(heap.Size() == 0);

    heap.Insert(5);
    heap.Insert(3);
    heap.Insert(7);

    assert(heap.Size() == 3);

    std::cout << "Size test passed." << std::endl;
}

void TestIsEmpty() {
    Heap<int> heap(5);

    assert(heap.IsEmpty());

    heap.Insert(5);

    assert(!heap.IsEmpty());

    std::cout << "IsEmpty test passed." << std::endl;
}