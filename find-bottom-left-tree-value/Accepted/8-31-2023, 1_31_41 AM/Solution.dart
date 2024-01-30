// https://leetcode.com/problems/find-bottom-left-tree-value

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */

class Pair<E, V>{
    E first;
    V second;

    Pair(this.first, this.second);
    
}
class Solution {

  void helper(TreeNode? root, int count, List<Pair<int, int>> l){
      if(root == null){
          return;
      }
      if(root.left == null && root.right == null){
          Pair<int, int> p = Pair<int, int>(count, root.val);
          l.add(p);
          return;
      }
      helper(root.left, count + 1, l);
      helper(root.right, count + 1, l);

  }
  int findBottomLeftValue(TreeNode? root) {
      int count = 0;
      List<Pair<int,int>> l = [];
      helper(root, count, l);
      int max = -1;
      int pos = -1;
      for(int i=0;i<l.length;i++){
          print(l[i].first);
          print(l[i].second);
          if(l[i].first > max){
              max = l[i].first;
              pos = l[i].second;
          }
      }

    return pos;
  }
}