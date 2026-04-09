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
    int find(vector<int> &inorder, int target, int start, int end)
    {
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode *Tree(vector<int> &inorder, vector<int> &preorder,
               int Instart, int Inend, int &index)
    {
        if(Instart > Inend)
            return NULL;

        TreeNode *root = new TreeNode(preorder[index++]);


        int pos = find(inorder, root->val, Instart, Inend);


        root->left = Tree(inorder, preorder, Instart, pos - 1, index);
        root->right = Tree(inorder, preorder, pos + 1, Inend, index);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        int index = 0;

        return Tree(inorder, preorder, 0, n - 1, index);
    }
};