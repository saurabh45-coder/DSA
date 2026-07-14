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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            TreeNode *temp1 = q.front();
            q.pop();
            if(!temp && !temp1)
                continue;
            if(!temp || !temp1)
                return false;
            if(temp->val != temp1->val)
                return false;
            q.push(temp->left);
            q.push(temp1->right);

            q.push(temp->right);
            q.push(temp1->left);
        }
        return true;
    }
};