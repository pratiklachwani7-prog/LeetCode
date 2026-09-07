class Solution {
public:
    bool dfs( int node , const vector<int>& edges , vector<int>& visited , vector<int>& pathSeq , int& ans)
    {
        visited[node] = 1 ;

        pathSeq.push_back( node ) ;
        if ( edges[node] != -1 )
        {
            int nbr = edges[node] ;
            if ( !visited[nbr] )
            {
                int res = dfs(nbr,edges , visited , pathSeq,ans) ;
                if ( res ) return true ;
            }
            else
            {
                auto iter = find( pathSeq.begin() , pathSeq.end() , nbr ) ;
                if ( iter != pathSeq.end() )
                {
                    int temp = pathSeq.size() - distance(pathSeq.begin(),iter) ;
                    ans = max( ans , temp ) ;
                    return true ;
                }
                
            }
        }
        pathSeq.pop_back(  ) ;
        return false ; 
    }
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size() ;
        vector<int> visited( n , 0 ) , pathSeq ;
        int ans = -1 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( !visited[i] ) dfs(i,edges,visited,pathSeq,ans) ;
            pathSeq.clear() ;
        }
        return ans ;

    }
};