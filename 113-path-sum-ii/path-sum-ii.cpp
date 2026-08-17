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
    void pathsum(TreeNode*root,int &targetSum,int sum,vector<int>&ans,vector<vector<int>> &result)
    {
        if(!root)
        {
            return;
        }
        sum += root->val;
        ans.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(sum == targetSum)
            {
                result.push_back(ans);
            }
        }
        pathsum(root->left,targetSum,sum,ans,result);
        pathsum(root->right,targetSum,sum,ans,result);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int>ans;
        pathsum(root,targetSum,0,ans,result);
        return result;
    }
};