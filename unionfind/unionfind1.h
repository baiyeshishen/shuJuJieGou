#ifndef UNION_FIND1
#define UNION_FIND1
#include<cassert>
class UnionFind1{
    private:
    int count;
    int*id;
    public:
    UnionFind1(int n){
        this->count=n;
        id=new int[n];
        for(int i=0;i<n;i++)
           id[i]=i;
    }

    ~UnionFind1(){delete [] id;}

    int find(int p){
        assert(p>=0&&p<count);
        return id[p];
    }

    bool isconnected(int p,int q){
        return id[p]==id[q];
    }

    void unionElements(int p,int q){
        int pid=find(p);
        int qid=find(q);
        if(pid==qid)
          return ;
        for(int i=0;i<count;i++)
            if(id[i]=pid)
                 id[i]=qid;
    } 
};
#endif