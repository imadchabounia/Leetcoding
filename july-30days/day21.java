//Same Algorithm with C++ will lead to a TLE
class Solution {
    
    private int[] dx = {1, -1, 0, 0};
    private int[] dy = {0, 0, -1, 1};
    
    private boolean go(char[][] board, String word, int i, int j, int k){
        if(k == word.length()) return true;
        int n = board.length;
        int m = board[0].length;
        if(i < 0 || j < 0 || j >= m || i >= n) return false;
        if(board[i][j] != word.charAt(k)) return false;
        char tmp = board[i][j];
        board[i][j] = '*';
        boolean ret = false;
        for(int kk = 0; kk < 4; kk++){
            ret = ret || go(board, word, i+dx[kk], j+dy[kk], k+1);
            if(ret) break;
        }
        board[i][j] = tmp;
        return ret;
    }
    
    public boolean exist(char[][] board, String word) {
        int n = board.length;
        if(n == 0) return false;
        int m = board[0].length;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(go(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
}
