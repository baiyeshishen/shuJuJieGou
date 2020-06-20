#ifndef LAZY_PRIM_H
#define LAZY_PRIM_H
#include"sparse_graph.h"
#include<vector>
#include<iostream>
#include"minHeap.h"
template<typename Graph,typename Weight>
class LazyPrimMst{
    private:
    Graph&graph;
    MinHeap<Edge<Weight>>pq;
    vector<Edge<Weight>>mst;
    bool*marked;
    Weight mstWeight;
    void visit(int i){
        assert(!marked[i]);
        marked[i]=true;
        typename Graph::adjIterator adj(graph,v);
        for(Edge<Weight>*e=adj.begin();!adj.end();e=adj.next())
             if(!marked[e->other(v)])
                 pq.insert(*e);
    }
    public:
    LazyPrimMst(Graph&G):graph(G),pq(MinHeap<Edge<Weight>>(G.E())){
        marked=new bool[G.V()];
        for(int i=0;i<G.V();i++)
            marked[i]=false;
        mst.clear();
        visit(0);
        while(!pq.empty()){
            Edge<Weight>e=pq.minElement();
            if(marked[e.v()]==marked[e.w()])
                 continue;
            mst.push_back(e);
            if(!marked[e.v()])
               visited[e.v()];
            else
            {
                visited[e.w()];
            }
        }
        mstWeight=mst[0].wt();
        for(int i=1;i<mst.size();i++)
             mstWeight+=mst[i].wt();
    }

    
};
#endif