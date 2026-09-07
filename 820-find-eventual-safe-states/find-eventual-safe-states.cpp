class Solution {
public:
    
    bool dfs( int node , const vector<vector<int>>& graph , vector<int>& visited , vector<int>& currentPath )
    {
        visited[node] = 1 ;

        currentPath[node] = 1 ;
        for ( int nbr : graph[node] )
        {
            if ( !visited[nbr] )
            {
                bool ans = dfs(nbr,graph,visited,currentPath) ;
                if (ans ) return true ;
            }
            else 
            {
                if ( currentPath[nbr] == 1 ) return true ;
            }
        }
        currentPath[node] = 0 ;
        return false ;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size() ;
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