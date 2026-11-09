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
    TreeNode* solve( vector<int>& inorder , int inStart , int inEnd , vector<int>& postorder , int postStart  , int postEnd  , unordered_map<int,int>& mp )
    {
        if ( inStart > inEnd || postStart > postEnd ) return nullptr ;

        TreeNode* root = new TreeNode( postorder[postEnd] ) ; 
        int inRoot = mp[root->val] ;
        
        int left = inRoot - ( inStart + 1 ) + 1 ;

        root->left = solve(inorder , inStart , inRoot - 1 , postorder , postStart , postStart + left - 1 ,mp) ;

        root->right = solve(inorder , inRoot + 1 , inEnd , postorder ,  postStart+left , postEnd - 1 , mp) ;

        return root ; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int,int> mp ;
        for ( int i = 0 ; i < inorder.size() ; i++ ) mp[inorder[i]] = i ;

        return solve( inorder , 0 , inorder.size() - 1 , postorder , 0 , postorder.size() - 1 , mp ) ;
    }
};