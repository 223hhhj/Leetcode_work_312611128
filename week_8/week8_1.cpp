/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // 如果 root 為空或是等於其中一個節點，直接回傳 root
            if (root == nullptr || root == p || root == q) {
                return root;
            }
    
            // 分別在左右子樹中尋找 p 和 q
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
            // 如果左右子樹各自找到一個節點，代表此 root 就是最近共同祖先
            if (left != nullptr && right != nullptr) {
                return root;
            }
    
            // 如果只有一邊有找到，就回傳那一邊
            return (left != nullptr) ? left : right;
        }
    };
    