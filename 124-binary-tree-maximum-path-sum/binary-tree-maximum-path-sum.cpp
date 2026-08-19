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
    int pathsum(TreeNode* root, int& sum)
    {
        if(!root)
            return 0;

        // Leaf node
        if(!root->left && !root->right)
        {
            sum = max(sum, root->val);
            return root->val;
        }

        int left = pathsum(root->left, sum);
        int right = pathsum(root->right, sum);

        // Both children exist
        if(root->left && root->right)
        {
            sum = max(sum, root->val + max(0, left) + max(0, right));

            return root->val + max(0, max(left, right));
        }

        // Only left child exists
        if(root->left)
        {
            sum = max(sum, root->val + max(0, left));

            return root->val + max(0, left);
        }

        // Only right child exists
        if(root->right)
        {
            sum = max(sum, root->val + max(0, right));

            return root->val + max(0, right);
        }

        return 0;
    }

    int maxPathSum(TreeNode* root)
    {
        int sum = INT_MIN;

        pathsum(root, sum);

        return sum;
    }
};