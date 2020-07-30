class Solution {
public:
    unordered_map<string, bool> m;
    unordered_map<int, vector<string>> dp;
    vector<string> solve(int i, string s, vector<string>& ss){
        if(i >= s.length()){
            return {""};
        }
        if(dp.find(i) != dp.end()) return dp[i];
        vector<string> ret;
        for(int j = i; j < (int)s.length(); j++){
            string prefix = s.substr(i, (j-i)+1);
            if(m[prefix]){
                vector<string> go = solve(j+1, s, ss);
                for(string sss : go){
                    if(go.size() == 0) continue;
                    string topush = prefix+" "+sss;
                    if(sss.length()==0) topush.pop_back();
                    ret.push_back(topush);
                }
            }
        }
        return dp[i] = ret;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string s : wordDict){
            m[s] = true;
        }
        vector<string> ss;
        vector<string> res = solve(0, s, ss);
        return res;
    }
};
