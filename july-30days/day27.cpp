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
    unordered_map<int, int> m;
    
    node* go(vector<int>& inorder, vector<int>& postorder, int l, int r){
        int n = inorder.size();
        if(l > r) return NULL;
        if(l == r) return new node(inorder[l]);
        int rootid = l;
        for(int i = l; i <= r; i++){
            if(m[inorder[rootid]] < m[inorder[i]]){
                rootid = i;
            }
        }
        node* root = new node(inorder[rootid]);
        root->left = go(inorder, postorder, l, rootid-1);
        root->right = go(inorder, postorder, rootid+1, r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            m[postorder[i]] = i;
        }
        node* root = go(inorder, postorder, 0, n-1);
        return root;
    }
};
