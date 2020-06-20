#ifndef UNION_FIND3
#define UNION_FIND3
#include<cassert>
class UnionFind3{
    private:
    int *parent;
    int *size;
    int count;
    public:
    UnionFind3(int count){
        this->count=count;
        parent=new int [count];
        size=new int[count];
        for(int i=0;i<count;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    ~UnionFind3(){
        delete [] id;
        delete[] size;
    }

    int find(int p){
        assert(p>=0&&p<count);
        while(p!=parent[p])
            p=parent[p];
        return p;
    }

    bool isconnected(int p,int q){
        return find(p)==find(q);
    }

    void unionElements(int p,int q){
        int proot=find(p);
        int qroot=find(q);
        if(proot==qroot)
          return;
        if(size[proot]<size[qroot]){
            parent[proot]=qroot;
            size[qroot]+=size[proot];
        }
        else if(size[proot]>size[qroot]){
            parent[qroot]=proot;
            size[proot]+=size[qroot];
        }
    }
};
#endif