#ifndef PATH_OF_TWO
#define PATH_OF_TWO
#include<stack>
#include<vector>
using namespace std;
template<typename Graph>
class Path{
    private:
    Graph&graph;
    int s;
    bool*visited;
    int *from;
    void path(int w, vector<int> &vec)
    {
        stack<int> s;
        int p = w;
        while (p != -1)
        {
            s.push(p);
            p = from[p];
        }
        vec.clear();
        while (!s.empty())
        {
            vec.push_back(s.top());
            s.pop();
        }
    }
     
     void dfs(int v){
        visited[v]=true;
        typename Graph::adjIterator adj(graph,v);
        for(int i=adj.begin();!adj.end();i=adj.next()){
            if(!visited[i]){
                from[i]=v;
                dfs[i];
            }
        }
     }
    public:
    Parh(int s,Graph&G):graph(G){
        assert(s>=0&&s<graph.V());
        visited=new int[graph.V()];
        from=new int [G.V()];
        for(int i=0;i<G.V();i++){
            visited[i]=false;
            from[i]=-1;
        }
        this->s=s;
        dfs(s);
    }

    ~Path(){
        delete[] visited;
        delete[] from;
    }

    bool hasPath(int w){
        assert(w>=0&&w<graph.V());
        return visited[w];
    }

    void showPath(int w){
        vector<int>vec;
        path(w,vec);
        for(int i=0;i<vec.size();i++){
            cout<<vec[i];
            if(i==vec.size()-1)
                cout<<endl;
            else 
                cout<<"->";
        }
    }
};
#endif