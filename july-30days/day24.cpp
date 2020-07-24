class Solution {
public:
    vector<int> g[15];
    vector<vector<int>> res;
    int n;
    
    void dfs(int u, vector<int>& tmp){
        tmp.push_back(u);
        if(u == n-1){
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        for(int v : g[u]){
            dfs(v, tmp);
        }
        tmp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        for(int i = 0; i < n; i++){
            int a = i;
            for(int j = 0; j < (int)graph[i].size(); j++){
                g[a].push_back(graph[i][j]);
            }
        }
        vector<int> path;
        dfs(0, path);
        return res;
    }
};
