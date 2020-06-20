#ifndef UNION_FIND5
#define UNION_FIND5
#include <cassert>
class UnionFind5
{
private:
    int *parent;
    int *rank;
    int count;

public:
    UnionFind5(int count)
    {
        this->count = count;
        parent = new int[count];
        rank = new int[count];
        for (int i = 0; i < count; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind5()
    {
        delete[] parent;
        delete[] rank;
    }
    //一层一层压缩并不是最优路径压缩；
    int find(int p)
    {
        assert(p >= 0 && p < count);
        while (p != parent[p])
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isconnected(int p, int q)
    {
        return find(p) == find(q);
    }

    void unionElements(int p, int q)
    {
        int proot = find(p);
        int qroot = find(q);
        if (proot == qroot)
            return;
        if (rank[proot] < rank[qroot])
            parent[proot] = qroot;
        else if (rank[proot] > rank[qroot])
            parent[qroot] = proot;
        else
        {
            parent[proot] = qroot;
            rank[qroot] += 1;
        }
    }
};
#endif