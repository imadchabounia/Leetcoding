class Solution {
private:
    //dsu solution
    int parent[100001];
    int size[100001];
    void make_set(int u){
        parent[u] = u;
        size[u] = 1;
    }
    int find_set(int u){
        if(parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }
    void union_sets(int u, int v){
        int a = find_set(u);
        int b = find_set(v);
        if(a != b){
            //union by size/rank
            if(size[b]>size[a]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int getId(int x, int y, int m){
        return x*m+y;
    }
public:
    void solve(vector<vector<char>>& grid) {
        //connect border nodes to a dummy node
        int n = grid.size();
        if(n == 0) return;
        int m = grid[0].size();
        memset(size,0,sizeof(size));
        memset(parent, -1, sizeof(parent));
        //a bad node is node who is connected to a boundry node
        //we will connect all bad nodes components to a dummy node
        int dnode_id = n*m;
        make_set(dnode_id);
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]=='O'){
                    make_set(getId(i,j,m));
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i==0 || i==n-1 || j==0 || j == m-1){
                    if(grid[i][j]=='O'){
                        int id = getId(i,j,m);
                        union_sets(dnode_id, id);
                    }
                }else if(grid[i][j]=='O'){
                    int id1 = getId(i, j, m);
                    for(int k = 0; k < 4; k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='O'){
                            int id2 = getId(ni, nj, m);
                            union_sets(id1,id2);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int id = getId(i,j,m);
                if(grid[i][j] =='O') if(find_set(id)!=find_set(dnode_id)) grid[i][j]='X';
            }
        }
    }
};
