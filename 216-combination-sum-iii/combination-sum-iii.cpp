class Solution {
public:
    void solve( int k , int n , vector<vector<int>>& ans , vector<int> temp , int idx )
    {
        if ( temp.size() == k )
        {
            int sumTemp = 0 ; 
            for ( int i = 0 ; i < temp.size() ; i++ ) sumTemp+=temp[i] ;
            if ( sumTemp == n ) ans.push_back( temp ) ;
            return ;
        }

        for ( int i = idx ; i <= 9 ; i++ )
        {
            temp.push_back( i ) ;
            solve( k , n , ans , temp , i+1 ) ;
            temp.pop_back() ;
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
        solve( k , n , ans , temp , 1) ;
        return ans ;
    }
};