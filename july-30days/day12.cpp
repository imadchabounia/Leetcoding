public class Solution {
    public int reverseBits(int n) {
        int res = 0;
        for(int i = 0; i <= 31; i++){
            int bit = (n>>i)&1;
            res = (res<<1)|bit;
        }
        return res;
    }
}   
