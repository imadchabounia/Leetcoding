class Solution {
public:
    vector<bool> onStack;
    vector<bool> visited1; //using "the visited array" while detecting cycle in a directed graph is optional (small optimization)
    vector<bool> visited2;
    vector<int> res;
    bool dfs(int u, vector<vector<int>>& g){
        onStack[u] = true;
        visited1[u] = true;
        for(int v : g[u]){
            if(onStack[v]) return true;
            if(!visited1[v] && dfs(v, g)) return true;
        }
        onStack[u] = false;
        return false;
    }
    void topSort(int u, vector<vector<int>>& g){
        visited2[u] = true;
        for(int v : g[u]){
            if(visited2[v]) continue;
            topSort(v, g);
        }        
        res.push_back(u);
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        //topological order
        //we need to verify that there is no cycles in the graph so we can do a topological sort
        vector<vector<int>> graph(n);
        onStack.resize(n);
        visited1.resize(n);
        visited2.resize(n);
        for(vector<int> e : prerequisites){
            int a = e[0];
            int b = e[1];
            graph[a].push_back(b);
            //unweighted directed graph
        }
        for(int i = 0; i < n; i++){
            if(visited1[i]) continue;
            if(dfs(i, graph)) return {};
        }
        for(int i = 0; i < n; i++){
            if(!visited2[i]) topSort(i, graph);
        }
        return res;        
    }
};
