/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    //Traveling Tree in InOrder Manner ( left - root - right)
     List<Integer>ans;
    
    void dfs(TreeNode node){
        if(node==null)return;
        dfs(node.left);
        ans.add(node.val);
        dfs(node.right);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        ans=new ArrayList();
        dfs(root);
        return ans;
        
    }
}