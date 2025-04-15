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
        int maxPathSum(TreeNode* root) {
            int maxSum = INT_MIN;
            maxPathSumHelper(root, maxSum);
            return maxSum;
        }
        
    private:
        // Returns the maximum single path sum (path that can be extended)
        // Updates maxSum with the maximum path sum found so far (including split paths)
        int maxPathSumHelper(TreeNode* node, int& maxSum) {
            if (!node) return 0;
            
            // Get max path sum from left and right subtrees
            // If the path sum is negative, we don't include it (use 0 instead)
            int leftMax = max(0, maxPathSumHelper(node->left, maxSum));
            int rightMax = max(0, maxPathSumHelper(node->right, maxSum));
            
            // Calculate the max path sum if we use this node as the turning point (split path)
            int currentMax = node->val + leftMax + rightMax;
            
            // Update the global maximum
            maxSum = max(maxSum, currentMax);
            
            // Return the maximum single path that can be extended from this node
            // We can only extend with either left or right path, not both
            return node->val + max(leftMax, rightMax);
        }
    };