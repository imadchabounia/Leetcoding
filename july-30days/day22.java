//another solution to day22 problem
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Deque<TreeNode> s1 = new LinkedList<TreeNode>();        
        Deque<TreeNode> s2 = new LinkedList<TreeNode>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(root != null){
            s1.offerLast(root);
        }
        while(!s1.isEmpty() || !s2.isEmpty()){
            List<Integer> tmp = new ArrayList<Integer>();
            if(!s1.isEmpty()){
                while(!s1.isEmpty()){
                    TreeNode n = s1.pollLast();
                    tmp.add(n.val);
                    if(n.left != null) s2.offerLast(n.left);
                    if(n.right != null) s2.offerLast(n.right);
                }
            }else if(!s2.isEmpty()){
                while(!s2.isEmpty()){
                    TreeNode n = s2.pollLast();
                    tmp.add(n.val);
                    if(n.right != null) s1.offerLast(n.right);
                    if(n.left != null) s1.offerLast(n.left);
                }
            }
            res.add(tmp);
        }
        return res;
    }
}
