#ifndef KRUSCAL_MST_H
#define KRUSCAL_MST_H
#include<vector>
#include"minHeap.h"
#include"unionfind6.h"
#include"edge.h"
using namespace std;
template<typename Weight>
class KruscalMst{
    private:
    vector<Edge<Weight>>mst;
    Weight mstWeight;
    public:
    KruscalMst(Graph&graph){
        MinHeap<Edge<Weight>>pq;
        for(int i=0;i<graph.V();i++){
            typename Graph::adjIterator adj(graph,i);
            for(Edge<Weight>*e=adj.begin();!adj.end();e=adj.next())
                if(e->v()<e->w()) //避免重复加入边；
                   pq.insert(*e);
        }
        UnionFind6 uf(graph.V());
        while(!pq.empty()&&mst.size()<graph.V()-1){
            Edge<Weight>e=pq.minElement();
            if(uf.isconnected(e.v(),e.w()))
                continue;
            mst.push_back(e);
            uf.unionElements(e.v(),e.w());
        }
        mstWeight=mst[0].wt();
        for(int i=1;i<mst.size();i++)
           mstWeight+=mst[i].wt();
    }

    ~KruscalMst(){}

    vector<Edge<Weight>>mstEdges(){
        return mst;
    }

    Weight result(){
        return mstWeight;
    }
};
#endif