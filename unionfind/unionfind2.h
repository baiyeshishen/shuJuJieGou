#ifndef UNION_FIND2
#define UNION_FIND2
#include<cassert>
class UnionFind2{
    private:
       int*parent;
       int count;
    public:
    UnionFind2(int n){
        this->count=n;
        parent=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    ~UnionFind2(){
        delete [] parent;
    }

    int find(int p){
        assert(p>=0&&p<count);
        while(p!=parent[p])
           p=parent[p];
        return p;
    }

    bool isconnected(int p, int q){
        return find(p)==find(q);
    }

    void unionElements(int p,int q){
        int proot=find(p);
        int qroot=find(q);
        if(proot==qroot)
           return;
        parent[proot]=qroot;
    }
};
#endif

