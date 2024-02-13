// implementing heap using array
/*
 * node == ( i )th index
 * left child = ( 2*i )th index
 * right child = ( 2*i+1 )th index
 * parent = ( i/2 )th index
 */

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class MaxHeap
{
    vector<T> heap;

public:
    MaxHeap()
    {
        heap = vector<T>(1);
    }

    void push(T data)
    {
        heap.push_back(data);
        int cur = heap.size() - 1;
        while (cur > 1)
        {
            if (heap[cur] > heap[cur / 2])
            {
                swap(heap[cur], heap[cur / 2]);
                cur /= 2;
            }
            else
                break;
        }
    }

    T pop()
    {
        if (heap.size() <= 1)
            throw length_error("No elements in heap to pop");
        T popped_value = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int cur = 1;
        while (cur < heap.size())
        {
            int left_child = 2 * cur;
            int right_child = 2 * cur + 1;
            if (left_child < heap.size() && heap[left_child] > heap[cur])
            {
                swap(heap[left_child], heap[cur]);
                cur = left_child;
            }
            else if (right_child < heap.size() && heap[right_child] > heap[cur])
            {
                swap(heap[right_child], heap[cur]);
                cur = right_child;
            }
            else
                break;
        }
        return popped_value;
    }

    void print()
    {
        for (T i : heap)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap<int> myHeap;
    myHeap.push(3);
    myHeap.push(2);
    myHeap.push(13);
    myHeap.push(1);
    myHeap.push(31);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.push(rand() % 100);
    myHeap.print();
    cout << "---" << myHeap.pop() << endl;
    myHeap.print();
    cout << "---" << myHeap.pop() << endl;
    myHeap.print();
    cout << "---" << myHeap.pop() << endl;
    myHeap.print();
    cout << "---" << myHeap.pop() << endl;
    myHeap.print();
    cout << "---" << myHeap.pop() << endl;
    myHeap.print();
    return 0;
}