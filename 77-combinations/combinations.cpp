class Solution {
public:
    void solve( int n , int k , vector<int>& temp , vector<vector<int>>& res , int idx )
    {
        if ( temp.size() == k )
        {
            res.push_back( temp ) ;
            return ;
        }
        for ( int i = idx ; i <= n ; i++ )
        {
            temp.push_back( i ) ;
            solve( n , k , temp , res , i + 1  ) ;
            temp.pop_back() ;
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res ;
        vector<int> temp ;
        solve( n , k , temp , res , 1 ) ;
        return res ;
    }
};