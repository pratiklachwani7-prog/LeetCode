class Solution {
public:
    vector<int> dp ;
    bool dfs( int node , const vector<vector<int>>& graph , vector<int>& visited , vector<int>& currentPath )
    {
        if ( dp[node] != -1 ) return dp[node] ;
        visited[node] = 1 ;

        currentPath[node] = 1 ;
        for ( int nbr : graph[node] )
        {
            if ( !visited[nbr] )
            {
                bool ans = dfs(nbr,graph,visited,currentPath) ;
                if (ans ) return dp[node] = true ;
            }
            else 
            {
                if ( currentPath[nbr] == 1 ) return dp[node] = true ;
            }
        }
        currentPath[node] = 0 ;
        return dp[node] = false ;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size() ;
        dp = vector<int>( n , -1 ) ;
        vector<int> visited(n,0) , currentPath(n,0) , res ;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( !visited[i] ) dfs(i,graph,visited,currentPath) ;
        }
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( currentPath[i] != 1 ) res.push_back( i ) ;
        }
        return res ;
    }
};