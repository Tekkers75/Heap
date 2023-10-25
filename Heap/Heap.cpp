﻿#include <iostream>
#include "Heap.h"
#include <algorithm>
#include <vector>
#include "Test.h"

int main() {
    Heap<int> heap(10);

    heap.Insert(5);
    heap.Insert(3);
    heap.Insert(7);
    heap.Insert(2);
    heap.Insert(4);
    heap.Insert(12);
    heap.Insert(1);


    //            12
    //    7               5
    //4       3       2       1

    //12 7 5 4 3 2 1

    std::cout << "Heap size: " << heap.Size() << std::endl;

    while (!heap.IsEmpty()) {
        int maxElement = heap.ExtractMax();
        std::cout << maxElement << " ";
    }

    std::cout << std::endl;


    std::vector<int> v{ 3, 2, 4, 1, 5, 9 };
    int* arr = new int[10]{ 3, 2, 4, 1, 5, 9 };





    // организует массив по принципу кучи (max heap)
    std::make_heap(v.begin(), v.end());

    //      9
    //	 / 	 \
    //   5     4
    //  / \    /
    // 1   2  3

    for (int x : v)
        std::cout << x << " ";
    // 9 5 4 1 2 3

    std::cout << "is_heap: " << is_heap(v.begin(), v.end());
    std::cout << std::endl;

    TestConstructor();
    TestInsert();
    TestExtractMax();
    TestSize();
    TestIsEmpty();







    return 0;
}