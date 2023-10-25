#pragma once
template <typename T>
class Heap
{
private:
	T* heapArray;
	int arraySize;
	int heapSize;

    //�������������� ������� ���� ����� ������� ��������. 
    void HeapifyUp(int index) {
        // ���� ������� ������ ��������� �� �������� �������,
        // �� ���������� ������� ����, � ��������� ��������.
        if (index == 0)
            return;
        // ��������� ������ ������������� ��������.
        int parent = (index - 1) / 2;
        // ���� �������� ������������� �������� ������ �������� �������� ��������,
        // �� ������ �� �������.
        if (heapArray[parent] < heapArray[index]) {
            std::swap(heapArray[parent], heapArray[index]);
        // ���������� �������� HeapifyUp ��� ������������� ��������,
        // ����� ��������� � ������������ �������� ���� ����.
            HeapifyUp(parent);
        }
    }

    //�������������� ������� ���� ����� �������� ������������� �������� 
    // ��� ��������� �������� ��������.
    void HeapifyDown(int index) {
        // ��������� ������� ������ � ������� �������� ���������.
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        // ������������, ��� ������� ������ �������� ���������� �������.
        int largest = index;

        // ���������, �������� �� ����� �������� ������� ������ �������� ����������� ��������.
        // ���� ��, �� ��������� ������ ����������� ��������.
        if (leftChild < heapSize && heapArray[leftChild] > heapArray[largest])
            largest = leftChild;
        // ���������, �������� �� ������ �������� ������� ������ �������� ����������� ��������.
        // ���� ��, �� ��������� ������ ����������� ��������.
        if (rightChild < heapSize && heapArray[rightChild] > heapArray[largest])
            largest = rightChild;
        // ���� ���������� ������� �� �������� ������� ���������,
        // �� ������ �� ������� � ���������� �������� HeapifyDown ��� ����������� ��������.
        if (largest != index) {
            std::swap(heapArray[index], heapArray[largest]);
            HeapifyDown(largest);
        }
    }

public:
    // ����������� ������ ����
    Heap(int capacity) : heapSize(0), arraySize(capacity) {
        heapArray = new T[arraySize];
    }

    // ���������� ������ ����
    ~Heap() {
        delete[] heapArray;
    }

    // ����� ��� ���������� �������� � ����
    void Insert(const T& item) {
        // ��������, ����� ���������, ��� ���� �� �������� ����� ������������ �������.
        if (heapSize == arraySize)
            throw std::out_of_range("Heap is full");

        // �������� ����� ������� � ����� ����
        heapArray[heapSize] = item;
        // �������� HeapifyUp ��� �������������� ������� ����
        HeapifyUp(heapSize);
        // ����������� ������ ����
        heapSize++;
    }

    // ����� ��� �������� � ����������� ������������� �������� �� ����
    T ExtractMax() {
        // ��������, ����� ���������, ��� ���� �� �������� ����� ������������ �������.
        if (heapSize == 0)
            throw std::out_of_range("Heap is empty");
        // ��������� ������� ������������ �������
        T maxElement = heapArray[0];
        // �������� ������ ���� ��������� ���������
        heapArray[0] = heapArray[heapSize - 1];
        // ��������� ������ ����
        heapSize--;
        // �������� HeapifyDown ��� �������������� ������� ����
        HeapifyDown(0);
        // ���������� ����������� ������������ �������
        return maxElement;
    }

    // ����� ��� ��������� �������� ������� ����
    int Size() const {
        return heapSize;
    }

    // ����� ��� ��������, ������ �� ����
    bool IsEmpty() const {
        return heapSize == 0;
    }

};
