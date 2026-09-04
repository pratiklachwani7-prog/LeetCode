    class Solution {
    public:
        vector<vector<int>> t ;
        int solve( const vector<vector<int>>& triangle , int idx , int minIdx  )
        {
            if ( idx >= triangle.size() ) return 0 ;
            if ( t[idx][minIdx] != INT_MIN ) return t[idx][minIdx] ;
            int pathOne = solve( triangle , idx+1 , minIdx ) ;
            int pathSecond = solve( triangle , idx+1 , minIdx+1 ) ;
            return t[idx][minIdx] = triangle[idx][minIdx] + min(pathOne , pathSecond) ;
        }
        int minimumTotal(vector<vector<int>>& triangle) 
        {
            t = vector< vector<int> > ( triangle.size() , vector<int> ( triangle.size() + 1 , INT_MIN  ) ) ;
            return solve( triangle , 0 , 0 ) ;
        }
    };