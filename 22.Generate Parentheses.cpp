//I just did this problem today
//the Solution can be optimized

class Solution {
public:

    vector<string> solve(string s, int no, int nc, int x){
        if(no == 0 && nc == 0 && x == 0){
            return {s};
        }else if(no == 0 && nc == 0 && x!=0) return {""};
        if(x<0) return {};
        vector<string> ret;
        vector<string> s1;
        if(no>0) s1 = solve(s+'(', no-1, nc, x+1);
        vector<string> s2;
        if(nc>0) s2 = solve(s+')', no, nc-1, x-1);
        for(auto& ss : s1){
            if(ss.length()==0) continue;
            ret.push_back(ss);
        }
        for(auto& ss : s2){
            if(ss.length()==0) continue;
            ret.push_back(ss);
        }
        return ret;
    }

    vector<string> generateParenthesis(int n) {
        return solve("", n, n, 0);
    }
};
