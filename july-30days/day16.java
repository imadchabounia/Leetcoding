class Solution {
    Map<Integer, Double> m = new HashMap<Integer, Double>();
    public double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(x == 1) return 1;
        if(x == -1){
            if(n%2 == 0) return 1;
            else return -1;
        }
        if(n == Integer.MIN_VALUE) return 0;
        if(m.containsKey(n)){
            return m.get(n);
        }
        boolean flag = false;
        if(n < 0) {
            flag = true;
            n = -n;
        }
        double left = myPow(x, n/2);
        double right = myPow(x, n/2);
        if(n%2 == 1){
            right *= x;
        }
        if(flag){
            return 1/(left*right);
        }
        m.put(n, left*right);
        return left*right;
    }
}
