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
    int ans ;
    int height(TreeNode* root)
    {
        if ( root == nullptr ) return 0 ; 

        return max( height(root->left) , height(root->right) ) + 1 ;
    }
    void solve( TreeNode* root )
    {
        if ( root == nullptr ) return ;
        int leftHeight = height(root->left) ;
        int rightHeight = height(root->right) ;

        ans = max(leftHeight + rightHeight , ans ) ;

        solve(root->left) ;
        solve(root->right) ;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        solve(root) ;
        return ans ;
    }
};