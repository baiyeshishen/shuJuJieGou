#ifndef DENSE_GRAPH_H_2
#define  DENSE_GRAPH_H_2
#include<iostream>
using namespace std;
template<typename Weight>
class DenseGraph2{
    private:
    int n,m;
    bool directed;
    vector<vecotr<Edge<Weight>*>>g;
    public:
    DenseGraph2(int n, bool directed){
        this->n=n;
        this->m=0;
        this->directed=directed;
        for(int i=0;i<n;i++)
           g.push_back(vector<bool>(n,NULL));
    }
    
    ~DenseGraph2(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
              if(g[i][j])
                 delete g[i][j];
        }
    }

    int V(){return n;}

    int E(){return m;}

    void addEdge(int a,int b,Weight weight){
        assert(a>=0&&a<n);
        assert(b>=0&&b<n);
        if(hasEdge(a,b)){
            delete g[a][b];
            m--;
            if(!directed)
               delete g[b][a];
        }
        g[a][b]=new Edge<Weight>(a,b,weight);
        if(!directed)
           g[b][a]=new Edge<Weight>(a,b,Weight);
        m++;
    }

    bool hasEdge(int v,int w){
        assert(v>=0&&v<n);
        assert(w>=0&&w<n);
        return g[v][w]!=NULL;
    }

    void show(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j])
                   cout<<g[i][j]->wt()<<"\t";
                else
                {
                       cout<<"NULL\t"
                }
                
            }
        cout<<endl;
        }
    }

    class adjIterator{
        private:
        DenseGraph2&G;
        int v;
        int index;
        public:
        adjIterator(DenseGraph2&graph,int v):G(graph){
            this->v=v;
            this->index=-1;
        }

        Edge<Weight>*begin(){
            index=-1;
            return next();
        }

        Edge<Weight>*next(){
            for(index+=1;index<G.V();index++)
                if(G.g[v][index])
                     return G.g[v][index];
            return NULL;
        }

        bool end(){
            return  index>=G.V();
        }
    };
};
#endif