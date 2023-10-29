//@author �������� �.�.
#pragma once
// ����� ���� max
template <typename T>
class Heap
{
private:
	T* heapArray;       // ��������� �� ������
	int arraySize;      // ������������ ������� ����
	int heapSize;       // ������� ������ ����

    //�������������� ������� ���� ����� ������� ��������. 
    void HeapifyUp(int index) {
        // ���� ������� ������ ��������� �� �������� �������,
        // �� ���������� ������� ����, � ��������� ��������. ==
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
        if (arraySize <= 0)
            throw std::out_of_range("Heap is full");
        heapArray = new T[arraySize];
    }

    // ���������� ������ ����
    ~Heap() {
        delete[] heapArray;
    }

    // ����� ��� ���������� �������� � ����
    void InsertOld(const T& item) {
        // ��������, ����� ���������, ��� ���� �� �������� ����� ������������ �������.
        if (heapSize == arraySize)
            throw std::out_of_range("Heap is full");
        // �������� ����� ������� � ����� ����
        heapArray[heapSize] = item;
        // ����������� ������ ����
        heapSize++;
        // �������� HeapifyUp ��� �������������� ������� ����
        HeapifyUp(heapSize-1);
    }


        //������� ������ �������� � ����������� ������� ����
    void Insert(T newNum)
    { //���� ������ ���� ������ ��� ����� ����
        if (heapSize >= arraySize)
        {
            // ������������ ������ ���� ���������
            int NewArraySize = arraySize * 2; // ���������� ������� � ��� ����
            //������������� ������
            T* newHeapArr = new T[NewArraySize];

            // ����������� ������������ ��������� � ����� ���� ������
            for (int i = 0; i < heapSize; i++)
            {
                newHeapArr[i] = heapArray[i];
            }

            // ������������ ������� ����� ������
            delete[] heapArray;

            // ���������� ��������� �� ����� ���� ������ � ������������� ������� ����
            heapArray = newHeapArr;
            arraySize = NewArraySize;

        }
        //���� ������ ����=0,���� �����
        if (heapSize == 0)
        {//����� ������� ���������� � ������ ����
            heapArray[0] = newNum;
            //������ ������������� �� 1
            heapSize++;
        }
        else
        { //����� ����� ������� ����������� � ����� ����
            heapArray[heapSize] = newNum;
            //������ ������������� �� 1
            heapSize++;
            //���� �������������� ������� � ���� ����
            //���� ����������� ��� ������� ������������� ��������,
            // ������� � ���������� �������� � �������� � ����� ����.
            for (int i = heapSize / 2 - 1; i >= 0; i--)
            {//�������������� ������� � ����
                HeapifyUp(i);
            }
        }
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


    //�������� ��������
    void deleteNode(T num)
    {
        int i;
        // ��������, ����� ���������, ��� ���� �� �����.
        if (heapSize == 0)
            throw std::out_of_range("Heap is empty");
        //�������� �� ��������� ����
        for (i = 0; i < heapSize; i++)
        {
            //���������� ������� � ��������� �������
            //���� ������� ������,���� �����������
            //� ������ ����������� � ���������� i 
            if (num == heapArray[i])
                break;
        }
        //���� ������ i ����� ������� ����,�� ������� � ���� �� �������
        if (i == heapSize)
        {
            throw std::out_of_range("Heap is empty");
        }
        //���� ������� ������
        //���������� ��������
        std::swap(heapArray[i], heapArray[heapSize - 1]);
        //������ ���� �����������
        heapSize--;
        //����� �������� ���������� �������������� � ���� ����
        HeapifyDown(i);
    }

    void print() {
        for (int i = 0; i < heapSize; i++)
        {
            std::cout << heapArray[i] << " ";
        }
        std::cout << std::endl;
    }


    // ����� ��� ������ �������� � ����
    bool Search(const T& item) const {
        for (int i = 0; i < heapSize; i++) {
            if (heapArray[i] == item) {
                std::cout << "Item found in heap" << std::endl;
                return true; // ������� ������
            }
        }
        std::cout << "Item not found in heap" << std::endl;
        return false; // ������� �� ������
    }

};
