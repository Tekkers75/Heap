#pragma once
template <typename T>
class Heap
{
private:
	T* heapArray;
	int arraySize;
	int heapSize;

    void HeapifyUp(int index) {
        if (index == 0)
            return;

        int parent = (index - 1) / 2;
        if (heapArray[parent] < heapArray[index]) {
            std::swap(heapArray[parent], heapArray[index]);
            HeapifyUp(parent);
        }
    }

    void HeapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heapSize && heapArray[leftChild] > heapArray[largest])
            largest = leftChild;

        if (rightChild < heapSize && heapArray[rightChild] > heapArray[largest])
            largest = rightChild;

        if (largest != index) {
            std::swap(heapArray[index], heapArray[largest]);
            HeapifyDown(largest);
        }
    }

public:
    Heap(int capacity) : heapSize(0), arraySize(capacity) {
        heapArray = new T[arraySize];
    }

    ~Heap() {
        delete[] heapArray;
    }

    // Метод для добавления элемента в кучу
    void Insert(const T& item) {
        if (heapSize == arraySize)
            throw std::out_of_range("Heap is full");

        heapArray[heapSize] = item;
        HeapifyUp(heapSize);
        heapSize++;
    }

    // Метод для удаления и возвращения максимального элемента из кучи
    T ExtractMax() {
        if (heapSize == 0)
            throw std::out_of_range("Heap is empty");

        T maxElement = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;

        HeapifyDown(0);

        return maxElement;
    }

    // Метод для получения текущего размера кучи
    int Size() const {
        return heapSize;
    }

    // Метод для проверки, пустая ли куча
    bool IsEmpty() const {
        return heapSize == 0;
    }

};
