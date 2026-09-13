class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        int n = digits.size() ; 
        vector<int> ans ;

        for ( int i = 0 ; i < n ; i++ )    
        {
            if ( digits[i] == 0 ) continue ;
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( i == j ) continue ;
                for ( int k = 0 ; k < n ; k++ )
                {
                    if ( i == j || j == k || i == k ) continue ;
                    if ( digits[k] % 2 != 0  ) continue ;
                    int temp = digits[i] * 100 + digits[j] * 10 + digits[k] * 1 ;
                    if ( find( ans.begin() , ans.end() , temp ) == ans.end() ) ans.push_back( temp ) ;
                }
            }
        }
        sort( ans.begin() , ans.end() ) ;
        return ans ;
    }
};