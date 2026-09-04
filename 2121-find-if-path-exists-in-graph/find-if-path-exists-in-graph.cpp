class Solution {
public:
    void dfs(const unordered_map< int , vector<int> >& graph , int source , vector<int>& visited)
    {
        visited[source] = 1 ;

        for ( auto nbr : graph.at(source) )
        {
            if ( !visited[nbr] ) dfs( graph , nbr , visited  ) ;
        }
        return ;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if ( edges.size() == 0 ) return true ;
        unordered_map< int , vector<int> > graph ;
        for ( int i = 0 ; i < edges.size() ; i++ )    
        {
            int a = edges[i][0] ;
            int b = edges[i][1] ;
            graph[a].push_back(b) ;
            graph[b].push_back(a) ;
        }
        vector<int> visited( n ) ;
        dfs(graph,source , visited) ;
        return visited[destination] ;
    }
};