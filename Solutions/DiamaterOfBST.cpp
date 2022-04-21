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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLength = 0;
        diameterOfSubBinaryTree(root, 0, maxLength);
        
        return maxLength;
    }
    
    int diameterOfSubBinaryTree(TreeNode* node, int depth, int& maxLength) {
        if (node->right == nullptr && node->left == nullptr) {
            maxLength = max(maxLength, depth);
            return depth;
        }
        
        int rightDepth = 0, leftDepth = 0;
        if (node->right != nullptr) {
            rightDepth = diameterOfSubBinaryTree(node->right, depth + 1, maxLength);
        }
        
        if (node->left != nullptr) {
            leftDepth = diameterOfSubBinaryTree(node->left, depth + 1, maxLength);
        }
        
        maxLength = max(maxLength, rightDepth + leftDepth - 2*depth);
        
        return max(rightDepth, leftDepth);
    }
};
