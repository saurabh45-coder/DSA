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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key)
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        else
        {
            // leaf node delete karna hai 
            if(!root->left  && !root->right)
            {
                delete root;
                return NULL;
            }
            // when exist 1 child
            //left child exist
            else if(!root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // right child exist
            else if(!root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            // both child exist
            else 
            {
                // find the greatest element from left side 
                TreeNode* child = root->left;
                TreeNode *parent = root;
                while(child ->right)
                {
                    parent = child;
                    child = child->right;
                }
                if(root != parent)
                {
                    parent->right = child->left;
                    child ->left = root->left;
                    child ->right =  root->right;
                    delete root;
                    return child;
                }
                else
                {
                    child ->right = root->right;
                    delete root;
                    return child;
                }
           }
        }
    }
};