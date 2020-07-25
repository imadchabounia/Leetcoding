class Solution {
public:
    //ok(m) : nums[m] < nums[0]
    int findMin(vector<int>& nums) {
        int l = 0;
        while(nums.size()>1 && nums.back() == nums[0]){
            nums.pop_back();
        }
        int h = (int)nums.size()-1;
        while(l < h){
            int m = (l + (long long)h) >> 1;
            if(nums[m] < nums[0]){
                h = m;
            }else{
                l = m+1;
            }
        }
        if(l == (int)nums.size()-1){
            return min(nums[l], nums[0]);
        }
        return nums[l];
    }
};
