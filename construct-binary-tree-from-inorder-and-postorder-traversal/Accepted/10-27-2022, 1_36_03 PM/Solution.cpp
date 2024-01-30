// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,int inS, int inE, int poS, int poE)
    {
        if(inS > inE)
        {
            return NULL;
        }
        int rootData = postorder[poE];
        TreeNode* temp = new TreeNode(rootData);
        int rootIndex = 0;
        for(int i=inS;i<=inE;i++)
        {
            if(inorder[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        }
        int lInS = inS;
        int lInE = rootIndex - 1;
        int lPoS = poS;
        int lPoE = lInE - lInS + lPoS;
        int rInS= rootIndex + 1;
        int rInE = inE;
        int rPoS = lPoE + 1;
        int rPoE = poE - 1 ;
        temp->left = buildTreeHelper(inorder, postorder, lInS, lInE, lPoS, lPoE);
        temp->right = buildTreeHelper(inorder, postorder, rInS, rInE, rPoS, rPoE);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return buildTreeHelper(inorder, postorder, 0, size-1, 0, size-1);
    }
};