#ifndef COMPONENT_H
#define COMPONENT_H
#include<iostream>
#include<cassert>
using namespace std;
template<typename Graph>
class Component{
    private:
    Graph&graph;
    int count;//连通分量个数；
    int *visited;
    int *id;//标记属于第几个分量；

    void dfs(int i){
        visited[i]=true;
        id[i]=count;
        typename graph::adjIterator adj(graph,i);
        for(int j=adj.begin();!adj.end();j=adj.next()){
            if(visited[j])
                continue;
            dfs(j);
        }
    }
    public:
    Component(Graph&G):graph(G){
        visited=new bool[G.V()];
        count=0;
        id=new int[G.V()];
        for(int i=0;i<G.V();i++){
            visited[i]=false;
            id[i]=-1;
        }
        for(int i=0;i<G.V();i++){
            if(!visited[i]){
                dfs(i);
                count++;
            }
        }
    }

    ~Component(){
        delete[] visited;
        delete[] id;
    }

    int count(){
        return count;
    }

    bool isConnected(int V,int W){
        assert(V>=0&&V<graph.V());
        assert(W>=0&&W<graph.V());
        return id[V]==id[W];
    }
};
#endif