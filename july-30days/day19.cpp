class Solution {
public:
    string addBinary(string a, string b) {
        while(a.length() < b.length()){
            a.insert(a.begin(), '0');
        }
        while(b.length() < a.length()){
            b.insert(b.begin(), '0');
        }
        string res = "";
        int n = a.length(); // == b.length();
        char carry = '0';
        for(int i = n-1; i >= 0; i--){
            char bit1 = a[i];
            char bit2 = b[i];
            if(bit1 == bit2){
                if(bit1 == '1'){
                    //res += carry;
                    res.insert(res.begin(), carry);
                    carry = '1';
                }else{
                    //res += carry;
                    res.insert(res.begin(), carry);
                    carry = '0';
                }
            }else{
                if(carry == '0'){
                    //res += '1';
                    res.insert(res.begin(), '1');
                }else{
                    //res += '0';
                    res.insert(res.begin(), '0');
                    carry = '1';
                }
            }
        }
        if(carry == '1') res.insert(res.begin(), '1');        
        return res;
    }
};
