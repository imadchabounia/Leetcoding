class Solution {
private:
    unordered_map<int, bool> m;
public:
    vector<vector<int>> f(int k, int n, int mask){
        if(n == 0 && k == 0){
            if(m[mask]) return {};
            vector<int> ret;
            for(int i = 0; i < 9; i++){
                int bit = (mask>>i)&1;
                if(bit&1) ret.push_back(i+1);
            }
            m[mask] = true;
            return  {{ret}};
        }else if(n <= 0){
            return {};
        }else if(k <= 0){
            return {};
        }
        vector<vector<int>> ret;
        for(int i = 0; i < 9; i++){
            int bit = (mask>>i)&1;
            if(bit&1) continue;
            int nmask = mask | (1<<i);
            vector<vector<int>> go = f(k-1, n-(i+1), nmask);
            if(go.size()>0) for(vector<int> v : go) ret.push_back(v);
        }
        return ret;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n==k && k>1) return {};
        vector<vector<int>> res = f(k,n,0);
        return res;
    }
};
