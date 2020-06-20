#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include"minIndexHeap.h"
#include<iostream>
#include<vector>
#include<cassert>
#include<stack>
using namespace std;
template<typename Graph,typename Weight>
class Dijkstra{
    private:
    Graph&G;
    int s;
    Weight*distTo;//到各个顶点的最小距离
    bool*marked;
    vector<Edge<Weight>*>from;
    public:
    Dijkstra(Graph&graph,int s):G(graph){
        this->s=s;
        distTo=new Weight[graph.V()];
        marked=new bool[graph.V()];
        for(int i=0;i<graph.V();i++){
            disTo[i]=Weight();//默认构造函数;
            marked[i]=false;
            from.push_back(NULL);
        }
        MinIndexHeap<Weight>ipq(G.V());
        distTo[s]=Wight();
        marked[s]=true;
        ipq.insert(s,distTo[s]);
        while(!ipq.empty()){
            int v=ipq.minElementIndex();
            marked[v]=true;
            typename Graph::adjIterator adj(G,V);//松弛操作；
            for(Edge<Weight>*e=adj.begin();!adj.end();e=adj.next()){
                int w=e->other(v);
                if(!marked[w]){
                    if(from[w]==NULL||distTo[v]+e->wt()<distTo[w]){
                        distTo[w]=distTo[v]+e->wt();
                        from[w]=e;
                    }
                    if(ipq.contain(w))
                        ipq.change(w,distTo[w]);
                    else
                        ipq.insert(w,distTo[w]);
                }
            }
        }
    }

    ~Dijkstra(){
        delete[] distTo;
        delete[] marked;
    }

    Weight shortestPathTo(int w){
        return disTo[w];
    }

    bool hasPathTo(int w){
        retuern marked[w];
    }

    void shortestPath(int w, vector<Edge<Weight>>&vec){
        stack<Edge<Weight>*>s;
        Edge<Weight>*e=from[w];
        while(e->v()!=e->w()){
            s.push(e);
            e=from[e->v()];
        }
        while (!s.empty()){
            e=s.top();
            vec.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w){
        assert(w>=0&&w<G.V());
        vector<Edge<Weight>>Vec;
        shortestPath(w,vec);
        for(int i=0;i<vec.size();i++){
            cout<<vec[i].v()<<"->";
            if(i==vec.size()-1)
               cout<<vec[i].w()<<endl;
        }
    }
};
#endif

