// https://leetcode.com/problems/increasing-order-search-tree

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class Solution {
    void helper(TreeNode? root, List<TreeNode> list){
        if(root == null){
            return;
        }
        helper(root.left, list);
        list.add(root);
        helper(root.right, list);

    }

    TreeNode? increasingBST(TreeNode? root) {
        List<TreeNode> list = [];
        helper(root, list);
        list[0].right = null;
        list[0].left = null;
        TreeNode? r = list[0];
        TreeNode? temp = r;
        for(int i=1;i<list.length;i++){
            list[i].left = null;
            list[i].right = null;
            temp?.right = list[i];
            temp = temp?.right;
        }
        return r;


    }
}