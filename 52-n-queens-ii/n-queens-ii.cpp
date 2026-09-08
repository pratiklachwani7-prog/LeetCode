class Solution {
public:
    bool checker(vector<vector<int>>& chessBoard , int nr , int nc )
    {
        int n = chessBoard.size() ;
        for ( int j = 0 ; j < n ; j++ )
        {
            if ( chessBoard[nr][j] == 1 ) return false ;
        }

        int i = nr , j = nc ;
        while ( i >= 0 && j >= 0 )
        {
            if ( chessBoard[i][j] == 1 ) return false ;
            i--;j--;
        }

        i = nr , j = nc ;
        while ( i < n && j >= 0 )
        {
            if ( chessBoard[i][j] == 1 ) return false ;
            i++;j--;
        }
        return true ;

    }
    void solve( int n , vector<vector<int>>& chessBoard , int sc ,vector<vector<int>>& res , 
    vector<int> temp)
    {
        if ( sc == n ) 
        {
            res.push_back( temp ) ;
            return ;
        }

        for (int i = 0 ; i < n ; i++ )
        {
            if ( checker( chessBoard , i , sc ) )    
            {
                chessBoard[i][sc] = 1 ; temp.push_back( i ) ;
                solve(n,chessBoard,sc+1,res,temp) ;
                chessBoard[i][sc] = 0 ;temp.pop_back() ;
            }
        }
        return ;
    }
    int totalNQueens(int n) 
    {
        vector<vector<int>> chessBoard( n , vector<int>( n , 0 ) ) ;
        vector<int> temp ;
        vector<vector<int>> res ;
        solve( n , chessBoard , 0 , res , temp ) ;
        return res.size() ;
    }
};