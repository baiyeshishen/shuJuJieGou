#ifndef MAXAX_INDEX_HEAP
#define MAX_INDEX_HEAP
#include <cassert>
#include<algorithm>
template <typename T>
class MaxIndexHeap
{
private:
    T *data;
    T *indexs;
    T *reverse;
    int count;
    int capacity;

    void shiftup(int i)
    {
        T item = data[indexs[i]];
        int index = indexs[i];
        while (i > 1 && data[indexs[i / 2]]<item)
        {
            indexs[i] = indexs[i / 2];
            reverse[indexs[i]] = i;
            i /= 2;
        }
        indexs[i] = index;
        reverse[index] = i;
    }

    void shiftdown(int i)
    {
        T item = data[indexs[i]];
        int index = indexs[i];
        while (2 * i <= count)
        {
            int j = 2 * i;
            if (j + 1 <= count && data[indexs[j]]<data[indexs[j + 1]])
                j++;
            if (data[indexs[j]]>item)
            {
                indexs[i] = indexs[j];
                reverse[indexs[i]] = i;
                i = j;
            }
            else
                break;
        }
        indexs[i] = index;
        reverse[index] = i;
    }

public:
    MaxIndexHeap(int capacity)
    {
        this->capacity = capacity;
        this->count = count;
        data = new T[capacity + 1];
        indexs = new T[capacity + 1];
        reverse = new T[capacity + 1];
    }

    ~MaxIndexHeap()
    {
        delete[] data;
        delete[] indexs;
        delete[] reverse;
    }

    int size()
    {
        return count;
    }

    bool empty()
    {
        return count == 0;
    }
    //传入的i对用户而言是从索引0开始的；
    void insert(int i, T item)
    {
        assert(count < capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);
        i++;
        data[i] = item;
        indexs[count + 1] = i;
        reverse[i] = count + 1;
        count++;
        shiftup(count);
    }

    T maxElement()
    {
        assert(count > 0);
        T item = data[indexs[1]];
        std::swap(indexs[1], indexs[count]);
        reverse[indexs[1]] = 1;
        reverse[indexs[count]] = 0; //表示已经不在索引堆中；
        count--;
        shiftdown(1);
        return item;
    }

    int maxElementIndex()
    {
        assert(count >= 1);
        int ret = indexs[1] - 1; //外部从0开始索引；
        std::swap(indexs[1], indexs[count]);
        reverse[indexs[1]] = 1;
        reverse[indexs[count]] = 0;
        count--;
        shiftdown(1);
        return ret;
    }
    //i为外部输入的索引；
    void change(int i, T item)
    {
        assert(contain(i));
        i++;
        data[i] = item;
        int j = reverse[i];
        shiftdown(j);
        shiftup(j);
    }

    bool contain(int i)
    {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return reverse[i + 1] != 0;
    }
};
#endif