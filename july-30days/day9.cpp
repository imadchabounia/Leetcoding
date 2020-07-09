
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
    unordered_map<int, long long> minH;
    unordered_map<int, long long> maxH;
    int res = 0;
    using node = TreeNode;
    void dfs(node* root, int level, long long i){
        if(root== nullptr) return;
        if(level >= 31) return;
        if(minH.count(level)){
            minH[level] = min(minH[level], i);
        }else{
            minH[level] = i;
        }
        maxH[level] = max(maxH[level], i);
        res = max(res, (int)(maxH[level]-minH[level]+1));
        if(root->left != NULL) dfs(root->left, level+1, i*2+1);
        if(root->right != NULL) dfs(root->right, level+1, 2*i+2);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return res;
    }
};
