class Solution {
public:
    vector<vector<int>> t ;
    int solve( int sr , int sc , int tr , int tc , const vector<vector<int>>& grid)
    {
        if ( sr == tr && sc == tc ) return grid[sr][sc] ;
        if ( t[sr][sc] != -1 ) return t[sr][sc] ;
        if ( sr == tr && sc != tc ) 
        {
            return t[sr][sc] = grid[sr][sc] + solve( sr , sc + 1 , tr , tc , grid ) ;
        }
        if ( sr != tr && sc == tc )
        {
            return t[sr][sc] = grid[sr][sc] + solve( sr + 1 , sc , tr , tc , grid ) ;
        }

        int pathOne = grid[sr][sc] + solve( sr , sc + 1 , tr , tc , grid) ;
        int pathSecond = grid[sr][sc] + solve( sr + 1 , sc , tr , tc , grid) ;
        return t[sr][sc] = min(pathOne , pathSecond) ;

    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size() ;
        int m = grid[0].size() ;
        t = vector<vector<int>>( n + 1 , vector<int>( m + 1 , -1  ) ) ;
        return solve( 0 , 0 , n - 1 , m - 1 , grid) ;
    }
};