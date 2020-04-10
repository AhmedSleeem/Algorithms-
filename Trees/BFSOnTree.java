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
    
   
    
    static class Pair{
        TreeNode node;

	//represent level which we are there
        int des;
    
        Pair (TreeNode node,int des){
            this.node=node;
            this.des=des;   
        }
    }
   
    
   
     
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>>ans=new ArrayList();
        
        if(root==null){
            return ans;
        }
         Queue<Pair> q;
		
        
        q=new LinkedList();
        q.add(new Pair(root,0));
        
        ArrayList<Integer>t=new ArrayList();
       
        int cur=0;
        while(!q.isEmpty())
        {
            Pair cur12=q.poll();
            if(cur12.des!=cur){
                ans.add(t);
                t=new ArrayList();
                t.add(cur12.node.val);
                ++cur;
               
            }else {
                t.add(cur12.node.val);
            }
            if(cur12.node.left!=null)q.add(new Pair(cur12.node.left,cur12.des+1));
            if(cur12.node.right!=null)q.add(new Pair(cur12.node.right,cur12.des+1));
            
            
            
        }
        ans.add(t);
        
        return ans;
        
    }
    
}



