class Solution {
public:
    void solve( int k , int n , vector<vector<int>>& ans , vector<int> temp , int idx , int sum )
    {
        if ( temp.size() == k && sum == n )
        {
            ans.push_back( temp ) ;
            return ;
        }

        for ( int i = idx ; i <= 9 ; i++ )
        {
            if ( i <= n - sum )
            {
                temp.push_back( i ) ;
                sum += i ;
                solve( k , n , ans , temp , i + 1 , sum ) ;
                sum -= i ;
                temp.pop_back() ;
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        if ( (k*(k+1)) / 2 > n ) return {} ;

        if ( (k*(k+1)) / 2 == n )
        {
            vector<int> temp ;
            for ( int i = 1 ; i <= k ; i++ ) temp.push_back( i ) ;
            return {temp} ;
        }
        vector<vector<int>> ans ;
        vector<int> temp ;
        solve( k , n , ans , temp , 1 , 0 ) ;
        return ans ;
    }
};