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
    int Sum( TreeNode* root , int& Count )
    {
        if ( root == NULL ) return 0 ;

        Count++ ;
        int sum = root->val + Sum( root->left , Count ) + Sum( root->right , Count )  ;
        return sum ;

    }
    void solve( TreeNode* root , int& answerCount )
    {
        if ( root == NULL ) return ;

        int count = 0 ;
        int avg = Sum( root , count ) ;
        avg = avg/count ;
        
        if ( avg == root->val ) answerCount++ ;
        solve(root->left , answerCount);
        solve(root->right , answerCount);
        
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int answerCount = 0 ;
        solve( root , answerCount ) ;
        return answerCount ;
    }
};