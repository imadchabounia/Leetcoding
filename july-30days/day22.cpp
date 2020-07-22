/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    using node = TreeNode;
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int step = 0;
        vector<vector<int>> res;
        queue<node*> q;
        if(root != NULL) q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp;
            while(size--){
                node* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
            if(step&1){
                reverse(tmp.begin(), tmp.end());
            }
            res.push_back(tmp);
            step++;
        }
        return res;
    }
};
