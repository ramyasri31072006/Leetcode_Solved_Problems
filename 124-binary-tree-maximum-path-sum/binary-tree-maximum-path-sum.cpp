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
    int solve(TreeNode* root,int & maxi,int& mini){
        if(root == NULL) return 0;
        int ls = max(0,solve(root->left,maxi,mini));
        int rs = max(0,solve(root->right,maxi,mini));
        maxi = max(maxi,ls+rs+root->val);
        mini = max(mini,root->val);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int maxi =0;
        int mini = INT_MIN;
        solve(root,maxi,mini);
        if(maxi == 0) return mini;
        return maxi;
    }
};