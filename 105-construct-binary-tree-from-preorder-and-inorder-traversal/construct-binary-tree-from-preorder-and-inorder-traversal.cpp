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
    TreeNode* solve( vector<int>& preorder , int preStart , int preEnd , vector<int>& inorder , int inStart , int inEnd )
    {
        if ( preStart > preEnd || inStart > inEnd ) return nullptr ;

        TreeNode* root = new TreeNode( preorder[preStart] ) ; 

        int value = preorder[preStart] ;
        
        int idx = -1 ;
        for ( int i = inStart ; i <= inEnd ; i++ ) if ( inorder[i] == value ) idx = i ;

        int l = idx - 1 - inStart + 1 ;
        root->left = solve(preorder , preStart + 1 , preStart + l , inorder , inStart , idx - 1 ) ;

        root->right  = solve( preorder , preStart + l + 1 , preEnd , inorder , idx + 1 , inEnd ) ;

        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        TreeNode* root = solve( preorder , 0 , preorder.size() - 1 , inorder , 0 , inorder.size() - 1 ) ;
        return root ;
    }
};