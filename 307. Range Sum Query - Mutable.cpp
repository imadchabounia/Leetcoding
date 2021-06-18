//implement a segment tree
class NumArray {
    int tree[(int)1e5+1];
    int n;
public:
    NumArray(vector<int>& nums) {
        memset(tree, 0, sizeof(tree));
        n = nums.size();
        //building segment tree
        for(int i = 0; i < n; i++){
            tree[i+n] = nums[i];
        }
        for(int i = n-1; i >= 1; i--){
            tree[i] = tree[2*i+1]+tree[2*i];
        }
    }

    void update(int index, int val) {
        index += n;
        tree[index] = val;
        for(int k = index/2; k >= 1; k /= 2){
            tree[k] = tree[2*k+1]+tree[2*k];
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while(left<=right){
            if(left%2==1){
                sum += tree[left++];
            }
            if(right%2==0){
                sum += tree[right--];
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
