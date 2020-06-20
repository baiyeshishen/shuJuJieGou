#ifndef MIN_HEAP
#define MIN_HEAP
#include <iostream>
#include <cassert>
#include<algorithm>
template <typename T>
class MinHeap
{
private:
    T *data;
    int count;
    int capacity;

    void shiftup(int i)
    {
        T item = data[i];
        while (i > 1 && data[i / 2] > item)
        {
        
                data[i] = data[i / 2];
                i /= 2;
            
        }
        data[i] = item;
    }

    void shiftdown(int i)
    {
        T item = data[i];
        while (i * 2 <= count)
        {
            int j = i * 2;
            if (j + 1 <= count && data[j + 1]<data[j])
                j += 1;
            if (data[j] < item)
            {
                data[i] = data[j];
                i = j;
            }
            else 
               break;
        }
        data[i] = item;
    }

public:
    MinHeap(int capacity)
    {
        data = new T[capacity + 1]; //索引从1开始；
        this->capacity = capacity;
        this->count = 0;
    }

    ~MinHeap()
    {
        delete[] data;
    }

    int size()
    {
        return count;
    }

    bool empty() { return count == 0; }

    void insert(T item)
    {
        assert(count < capacity);
        data[++count] = item;
        shiftup(count);
    }

    T minElement()
    {
        assert(count > 0);
        T item = data[1];
        std::swap(data[1], data[count]);
        count--;
        shiftdown(1);
        return item;
    }

   /* MinHeap(T arr[], int n)
    {
        data = new T[n + 1];
        this->capacity = n;
        for (int i = 0; i < n; i++)
        {
            data[i + 1] = arr[i]; //data从1开始索引0不使用；
        }
        count = n;
        for (int i = count / 2; i >= 1; i--)
            shifdown(i);
    }
    */
};
#endif