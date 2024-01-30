// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inS, int inE, int prS, int prE)
    {
        if(inS > inE)
        {
            return NULL;
        }
        int root = preorder[prS];
        int rootIndex = -1;
        TreeNode* temp = new TreeNode(root);
        for(int i=inS;i<=inE;i++)
        {
            if(inorder[i] == root)
            {
                rootIndex = i;
                break;
            }
        }
        int lInS = inS;
        int lInE = rootIndex - 1;
        int lPrS = prS + 1;
        int lPrE = lInE - lInS + lPrS;
        int rInS = rootIndex + 1;
        int rInE = inE;
        int rPrS = lPrE + 1;
        int rPrE = prE;
        temp->left = buildTreeHelper(preorder, inorder, lInS, lInE, lPrS, lPrE);
        temp->right = buildTreeHelper(preorder, inorder, rInS, rInE, rPrS, rPrE);
        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        return buildTreeHelper(preorder, inorder,0,size-1,0,size-1);
        
    }
};