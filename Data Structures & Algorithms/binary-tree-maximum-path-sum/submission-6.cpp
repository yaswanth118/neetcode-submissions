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
    pair<int,int> dfs(TreeNode* root) {
        // max unitl now  , it's max continnum path.
        pair<int,int> lft = (root->left == nullptr ? make_pair(INT_MIN,0) : dfs(root->left));
        pair<int,int> rht = (root->right == nullptr ? make_pair(INT_MIN,0) : dfs(root->right));
        
        int mx = max(lft.first, max(rht.first, root->val + lft.second + rht.second));

        return {mx, max(0,root->val + max(lft.second, rht.second))};

    }

    int maxPathSum(TreeNode* root) { return dfs(root).first; }
};
