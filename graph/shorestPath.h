#ifndef SHOWEST_PATH
#define SHOWEST_PATH
#include<queue>
#include<stack>
template<typename Graph>
class ShorestPath{
    private:
    Graph&graph;
    int s;
    bool*visited;
    int*from;
    int*ord;//s到每个节点的最短距离；
    public:
    ShorestPath(Graph&G,int s):graph(G){
        assert(s>=0&&s<graph.V());
        visited=new bool[graph.V()];
        from=new int [graph.V()];
        ord=new  int [grapb.V()];
        for(int i=0;i<graph.V();i++){
            visited[i]=false;
            from[i]=-1;
            ord[i]=-1;
        }
        this->s=s;
        queue<int>q;
        q.push(s);
        visited[s]=true;
        ord[s]=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            typename Graph::adjIterator adj(graph,v);
            for(int i=adj.begin();!adj.end();i=adj.next()){
                if(!visited[i]){
                    from[i]=v;
                    visted[i]=true;
                    ord[i]=ord[v]+1;
                    q.push(i);
                }
            }
        }
    }

    ~ShorestPath(){
        delete[] visited;
        delete[] from;
        delete[] ordl;
    }

    bool hasPath(int w){
        assert(w>=0&&w<graph.V());
        return visited[w];
    }

    void path(int w,vector<int>&vec){
        assert(w>=0&&w<G.V());
        stack<int>s;
        int p=w;
        while(p!=-1){
            s.push(p);
            p=from[p];
        }
        vec.clear();
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int w){
        assert(w>=0&&w<graph.V());
        vector<int>res;
        parh(w,res);
        for(int i=0;i<res.size();i++){
            cout<<res[i];
            if(i==res.size()-1)
              cout<<endl;
            else
               cout<<"->";
        }
    }

    int length(int w){
        assert(w>=0&&w<graph.V());
        return ord[w];
    }
};
#endif