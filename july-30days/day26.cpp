class Solution {
public:
    int addHelper(int num){
        int res = 0;
        while(num){
            res += num%10;
            num /= 10;
        }
        return res;
    }
    int addDigits(int num) {
        while(num/10){
            num = addHelper(num);
        }
        return num;
    }
};
/* Best Approach
class Solution {
public:
    int addDigits(int num) {
        //digital root;
        if(num==0) return 0;
        if(num%9 == 0) return 9;
        return (num%9);
    }
};
*/
