class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            // Create a map to store the indices of elements in inorder traversal
            unordered_map<int, int> inorderMap;
            for (int i = 0; i < inorder.size(); i++) {
                inorderMap[inorder[i]] = i;
            }
            
            return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
        }
        
    private:
        TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                                vector<int>& inorder, int inStart, int inEnd, 
                                unordered_map<int, int>& inorderMap) {
            // Base case: if no elements to construct the tree
            if (preStart > preEnd || inStart > inEnd) {
                return nullptr;
            }
            
            // The first element in preorder is the root
            int rootVal = preorder[preStart];
            TreeNode* root = new TreeNode(rootVal);
            
            // Find the position of the root in inorder
            int rootIndexInorder = inorderMap[rootVal];
            
            // Number of elements in left subtree
            int leftSubtreeSize = rootIndexInorder - inStart;
            
            // Recursively build left subtree
            // preorder: [preStart+1, preStart+leftSubtreeSize]
            // inorder: [inStart, rootIndexInorder-1]
            root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, 
                                      inorder, inStart, rootIndexInorder - 1, inorderMap);
            
            // Recursively build right subtree
            // preorder: [preStart+leftSubtreeSize+1, preEnd]
            // inorder: [rootIndexInorder+1, inEnd]
            root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, 
                                       inorder, rootIndexInorder + 1, inEnd, inorderMap);
            
            return root;
        }
    };