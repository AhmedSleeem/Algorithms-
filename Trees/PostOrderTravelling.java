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
    
    //Traveling Tree in PostOrder Manner( left - right - root)
      List<Integer>ans;
    
    void dfs(TreeNode node){
        if(node==null)return;
        dfs(node.left);
       
        dfs(node.right);
         ans.add(node.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
    
        ans=new ArrayList();
        dfs(root);
        return ans;
        
    }
}