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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if ( root == nullptr ) return {} ;

        vector<vector<int>> ans ;
        int flag = 0 ; 
        queue<TreeNode*> q ;
        q.push(root) ;

        while ( !q.empty() )
        {
            vector<int> level ;
            int n = q.size() ;

            while ( n-- )
            {
                TreeNode* node = q.front() ;
                q.pop() ;

                if ( node->left != nullptr ) q.push( node->left ) ;
                if ( node->right != nullptr ) q.push( node->right ) ;

                level.push_back(node->val) ;
            }
            if ( flag ) reverse(level.begin() , level.end() ) ;

            ans.push_back(level) ;
            flag = !flag ;
        }
        return ans ;
    }
};