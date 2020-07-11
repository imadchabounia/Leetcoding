class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int i, vector<int>& subset){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        solve(nums, i+1, subset);
        subset.push_back(nums[i]);
        solve(nums, i+1, subset);
        subset.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        solve(nums, 0, subset);
        return res;
    }
};

//Solution2
/*
class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums, int i, vector<int> subset){
        if(i == nums.size()){
            return {subset};
        }
        vector<vector<int>> res;
        vector<vector<int>> left = solve(nums, i+1, subset);
        for(vector<int> v : left) res.push_back(v);
        subset.push_back(nums[i]);
        vector<vector<int>> right = solve(nums, i+1, subset);
        for(vector<int> v : right) res.push_back(v);
        return res;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums, 0, {});
        //return res;
    }
*/
	
