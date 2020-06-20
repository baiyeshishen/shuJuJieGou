#ifndef UNION_FIND6
#define UNION_FIND6
#include<cassert>
class UnionFind6{
    private:
    int*parent;
    int* rank;
    int count;
    public:
    UnionFind6(int count){
        this->count=count;
        parent=new int[count];
        rank=new int[count];
        for(int i=0;i<count;i++){
             parent[i]=i;
             rank[i]=1;
        }
    }

    ~UnionFind6(){
        delete[]parent;
        delete[] rank;
    }

    int find(int p){
        assert(p>=0&&p<count);
        if(parent[p]==p)
          return parent[p];
        parent[p]=find(parent[p]);
        return parent[p];
    }

    bool isconnected(int p,int q){
        return find(p)==find(q);
    }

    void unionElements(int p,int q){
        int proot=find(p);
        int qroot=find(q);
        if(proot==qroot)
          return;
        if(rank[proot]<rank[qroot])
              parent[proot]=qroot;
        else if(rank[qroot]<rank[proot])
              parent[qroot]=proot;
        else{
            rank[proot]=qroot;
            rank[qroot]+=1;
        }
    }
};
#endif