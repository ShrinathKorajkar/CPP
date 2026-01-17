#include <iostream>
#include <algorithm>
#include <vector>

class MaxHeap
{
private:
    std::vector<int> heap;

    // Fix heap DOWNWARD from index i  (used in pop & build heap)
    void heapifyDown(int i)
    {
        int size = heap.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < size && heap[left] > heap[largest])
            largest = left;

        // Check right child
        if (right < size && heap[right] > heap[largest])
            largest = right;

        // If largest is not parent, swap & continue heapifying
        if (largest != i)
        {
            std::swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Fix heap UPWARD from index i (used in push)
    void heapifyUp(int i)
    {
        int parent = (i - 1) / 2;

        if (i > 0 && heap[i] > heap[parent])
        {
            std::swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    // Insert element → O(log n)
    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Remove max element → O(log n)
    int pop()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Heap is empty");
        }

        int root = heap[0];    // max element
        heap[0] = heap.back(); // move last to root
        heap.pop_back();       // remove last
        if (!heap.empty())
            heapifyDown(0); // restore heap

        return root;
    }

    void make_heap_custom()
    {
        int n = heap.size();

        // last non-leaf node = n/2 - 1
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }

    // Return max → O(1)
    int top() const
    {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");

        return heap[0];
    }

    bool empty() const
    {
        return heap.size() == 0;
    }

    int size() const
    {
        return heap.size();
    }

    void print()
    {
        for (int x : heap)
            std::cout << x << " ";
        std::cout << "\n";
    }
};

int main()
{
    std::vector<int> heap = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::make_heap(heap.begin(), heap.end());

    heap.push_back(10);
    std::push_heap(heap.begin(), heap.end());

    std::pop_heap(heap.begin(), heap.end());
    int max = heap.back();
    heap.pop_back();

    std::sort_heap(heap.begin(), heap.end());

    for (const auto &element : heap)
    {
        std::cout << element << " ";
    }

    std::cout << "\nMaximum: " << max << std::endl;

    //
    // Custom heap
    MaxHeap h;

    h.push(20);
    h.push(15);
    h.push(30);
    h.push(40);

    h.print(); // heap in array form

    std::cout << "Max: " << h.top() << std::endl;

    std::cout << "Pop: " << h.pop() << std::endl;
    std::cout << "Pop: " << h.pop() << std::endl;

    h.print();
    return 0;
}
