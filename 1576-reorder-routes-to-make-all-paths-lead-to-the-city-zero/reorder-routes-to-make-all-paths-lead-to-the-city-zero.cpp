class Solution {
public:
    void solve(const vector<vector<int>>& frontEnd , const vector<vector<int>>& backEnd  , int& res , int source ,  vector<int>& visited)
    {
        queue<int> q ;
        q.push(source) ;
        visited[source] = 1 ;

        while( !q.empty()  )
        {
            int f = q.front() ; 
            q.pop() ;

            for ( int nbr : frontEnd[f] )
            {
                if ( !visited[nbr] ) 
                {
                    res++;
                    q.push(nbr) ;
                    visited[nbr] = 1 ;
                }
            }
            for ( int nbr : backEnd[f] )
            {
                if ( !visited[nbr] )
                {
                    q.push(nbr) ;
                    visited[nbr] = 1 ;
                }
            }
        }
        return ;

    }
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector< vector<int> > frontEnd(n+1) ;
        vector< vector<int> > backEnd(n+1) ;
        for ( int i = 0 ; i < connections.size() ; i++ )
        {
            int a = connections[i][0] ;
            int b = connections[i][1] ;
            frontEnd[a].push_back(b) ;
            backEnd[b].push_back(a) ;
        }
        int res = 0;
        vector<int> visited(n , 0) ;
        solve(frontEnd , backEnd , res , 0 , visited ) ;
        return res ;
        
    }
};