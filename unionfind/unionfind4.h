#ifndef UNION_FIND4
#define UNION_FIND4
#include<cassert>
class UnionFind4{
    private:
    int*parent;
    int *rank;
    int count;
    public:
    UnionFind4(int count){
        this->count=count;
        parent=new int[count];
        rank=new int[count];
        for(int i=0;i<count;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    ~UnionFind4(){
        delete[] id;
        delete[] rank;
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

    void nuionElements(int p, int q){
        int proot=find(p);
        int qroot=find(q);
        if(proot=qroot)
           return;
        if(rank[proot]<rank[qroot]){
            parent[proot]=qroot;
        }
        else if(rank[qroot]<rank[proot])
              parent[qroot]=proot;
        else{
            parent[proot]=qroot;
            rank[qroot]+=1;
        }
    }
};
#endif