// https://leetcode.com/problems/linked-list-in-binary-tree

/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
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
  bool isSamePath(ListNode? head, TreeNode? root){
    if(root == null && head != null){
        return false;
    }
    if(root == null && head == null){
        return true;
    }
    if(head == null){
        return true;
    }
    return (head?.val == root?.val) && (isSamePath(head?.next, root?.left) || isSamePath(head?.next, root?.right));
  }
  bool isSubPath(ListNode? head, TreeNode? root) {
      if(root == null){
        return false;
      }
      if(isSamePath(head, root)){
        return true;
      }
      return isSubPath(head, root?.left) || isSubPath(head, root?.right);

  }
}