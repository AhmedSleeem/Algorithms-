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
    
    //Traveling Tree in PreOrder manner(root - left - right)
     List<Integer>ans;
    
    void dfs(TreeNode node){
        if(node==null)return;
        ans.add(node.val);
        dfs(node.left);
        dfs(node.right);
    }
    
    public List<Integer> preorderTraversal(TreeNode root) {
    
        ans=new ArrayList();
        
        dfs(root);
        return ans;
        
    }
}