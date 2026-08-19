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
    void pathsum(TreeNode *root,int currentNumber,int &sum)
    {
        if(!root) return;
        currentNumber = currentNumber*10 + root->val;

        if(!root->left && !root->right)
        {
            sum = sum + currentNumber;
        }
        pathsum(root->left,currentNumber,sum);
        pathsum(root->right,currentNumber,sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum =0;
        pathsum(root,0,sum);
        return sum;
    }
};