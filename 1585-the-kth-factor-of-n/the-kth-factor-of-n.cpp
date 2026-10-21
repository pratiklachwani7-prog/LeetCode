class Solution {
public:
    int kthFactor(int n, int k) 
    {
        if ( k == 1 ) return 1 ; 
        
        vector<int> factors ;
        factors.push_back(1) ;

        for ( int i = 2 ; i <= n ; i++)
        {
            if ( n % i == 0 ) factors.push_back( i ) ;
        }
        
        if ( k > factors.size() ) return -1 ;
        else return factors[k-1] ;
    }
};