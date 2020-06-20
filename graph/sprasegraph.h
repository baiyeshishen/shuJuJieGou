#ifndef    SPARSE_GRAPH
#define    SPARSE_GRAPH
#include<vector>
#include<cassert>
using namespace std;
class SparseGraph{
    private:
    int n,m;
    int directed;
    vector<vector<int>>g;//邻接表实现；

    bool hasEdge(int v,int w){
        assert(v>=0&&v<n);
        assert(w>=0&&w<n);
        for(int i=0;i<g[v].size();i++)
             if(g[v][i]==w)
                 return true;
        return false;
    }
    public:
    SparseGraph(int v,bool directed){
        this->n=n;
        this->m=0;
        this->directed=directed;
        for(int i=0;i<n;i++)
           g.push_back(vector<int>());
    }

    ~SparseGraph(){}

    int V(){return n;}

    int E(){return m;}

    void addEdge(int v,int w){
        assert(v>=0&&v<n);
        assert(w>=0&&w<n);
        //if(hasEdge(v,w))
          //  return;       //忽略平行边，加完边之后再删除；
        g[v].push_back(w);
        if(!directed&&v!=w)//处理自环边；
           g[w].push_back(v);
        m++;
    }

    class adjIterator{
        private:
        int v;
        int index;
        SparseGraph&G;
        public:
        adjIterator(SparseGraph&graph,int v):G(graph){
            this->v=v;
            this->index=0;
        }

        int begin(){
            index=0;
            if(G.g[v].size())
               return G.g[v][index];
            return -1;
        }

        int next(){
            index++;
            if(index<G.g[v].size())
              return G.g[v][index];
            return -1;
        }

        bool end(){
            return index>=G.g[v].size();
        }
    };

};
#endif