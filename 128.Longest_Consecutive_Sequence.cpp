class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    void make_set(int u){
        parent[u] = u;
        size[u] = 1;
        return;
    }
    int find_set(int u, bool& flag){
        if(parent.count(u) == 0){
            flag = false;
            return -1;
        }
        if(parent[u] == u) return u;
        return parent[u] = find_set(parent[u],flag);
    }
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }
    void union_sets(int u, int v){
        bool f;
        int a = find_set(u,f);
        int b = find_set(v,f);
        if(a!=b){
            if(size[b]>size[a]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
        return;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for(int x : nums) make_set(x);
        int res = 0;
        for(int x : nums){
            int u = x;
            bool f = true;
            find_set(x-1,f);
            if(f == true){
                int v = x-1;
                union_sets(u,v);
                continue;
            }
            f = true;
            find_set(x+1,f);
            if(f){
                int v = x+1;
                union_sets(u,v);
                continue;
            }
        }
        for(int x : nums){
            bool f;
            res = max(res, size[find_set(x,f)]);
        }
        return res;
    }
};
