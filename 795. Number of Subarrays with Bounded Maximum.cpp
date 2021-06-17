const int mmax=1e5+3;
class Solution {
public:

    int solve(const vector<int>& nums, int left, int right, int i, int j){
        if(i>j || i>=(int)nums.size() || j<0) return 0;
        int mmax = -1;
        int pos = -1;
        for(int k = i; k <= j; k++){
            if(nums[k]>mmax){
                mmax = nums[k];
                pos = k;
            }
        }
        if(mmax<left || mmax>right){
            return solve(nums, left, right, i, pos-1)+solve(nums, left, right, pos+1, j);
        }else{
            return (pos-i+1)*(j-pos+1)+solve(nums, left, right, i, pos-1)+solve(nums, left, right, pos+1, j);
        }
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        return solve(nums, left, right, 0, n-1);
    }
};
