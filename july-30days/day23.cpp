class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor2 = 0;
        for(int x : nums) xor2 ^= x;
        int a = 0;
        int b = 0;
        int pos = -1;
        for(int i = 0; i <= 31; i++){
            int bit = ((xor2>>i)&1);
            if(bit){
                pos = i;
                break;
            }
        }
        for(int x : nums){
            int bit = ((x>>pos)&1);
            if(bit==1) a ^= x;
            else b ^= x;
        }
        return {a,b};
    }
};
