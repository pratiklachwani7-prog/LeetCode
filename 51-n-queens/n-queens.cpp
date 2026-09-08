class Solution {
public:
    bool checker( vector< vector<int> >& chessBoard , int nr , int nc)
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
        while ( i < n  && j >= 0 )
        {
            if ( chessBoard[i][j] == 1 ) return false ;
            i++;j--;
        }
        return true ;
    }
    void solve( int n , vector< vector<int> >& chessBoard , int sc , vector<vector<int>>& res , vector<int> temp)
    {
        if ( sc == n )
        {
            res.push_back(temp) ;
            return ;
        }

        for ( int i = 0 ; i < n ; i++ )
        {
            if ( checker( chessBoard , i , sc ) )
            {
                temp.push_back( i ) ; chessBoard[i][sc] = 1 ;
                solve( n , chessBoard , sc+1 , res , temp ) ;
                temp.pop_back() ; chessBoard[i][sc] = 0 ;
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector< vector<int> > chessBoard( n , vector<int>( n , 0 ) ) ;
        vector<vector<int>> res ;
        vector<int> temp ;
        solve( n , chessBoard , 0 , res , temp ) ;

        vector<vector<string>> answer ;
        vector<string> helper1 ;
        string helper2 ;
        for ( int i = 0 ; i < n ; i++ ) helper2.push_back('.') ;

        for ( int i = 0 ; i < res.size() ; i++ )
        {
            for ( int j = 0 ; j < res[i].size() ; j++ )
            {
                helper2[ res[i][j] ] = 'Q' ;
                helper1.push_back( helper2 ) ;
                helper2[ res[i][j] ] = '.' ;
            }
            answer.push_back( helper1 ) ;
            helper1.clear() ;
        }
        
        return answer; ;
    }
};