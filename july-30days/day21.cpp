class Solution {
public:
        
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    bool go(vector<vector<char>>& board, string word, int i, int j, int k){
        int n = board.size();
        int m = board[0].size();
        if(k == word.size()) return true;
        if(i < 0 || j < 0 || j >= m || i >= n) return false;
        if(board[i][j] != word[k]) return false;
        char tmp = board[i][j];
        board[i][j] = '*';
        bool ret = false;
        for(int kk = 0; kk<4; kk++){
            ret = ret||(go(board, word, i+dx[kk], j+dy[kk], k+1));
            if(ret) break;
        }
        board[i][j] = tmp;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(n == 0) return false;
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(go(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
