class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        Deque<String> stack = new LinkedList<String>();
        String curr = "";
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == ' ' || i == n-1){
                if(i == n-1 && s.charAt(i) != ' '){
                    curr += s.charAt(i);
                }
                if(stack.isEmpty()){
                    if(curr.length() > 0) stack.offerLast(curr);
                }else{
                    if(curr.length() > 0) stack.offerLast(curr+' ');
                }
                curr = "";
            }else{
                curr += s.charAt(i);
            }
        }
        String res = "";
        while(!stack.isEmpty()){
            res += stack.pollLast();
        }
        return res;
    }
}
