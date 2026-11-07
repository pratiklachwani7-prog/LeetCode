class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxi = INT_MIN , n = piles.size() ;
        for ( int i = 0 ; i < n ; i++  ) maxi = max( maxi , piles[i] ) ;

        int low = 1 , high = maxi , ans = INT_MAX ; 

        while ( low <= high )
        {
            int mid = low + ( high - low ) / 2 ;

            long long check = 0 ; 
            for ( int i = 0 ; i < n ; i++ ) 
            {
                check += ceil( (double)piles[i] / (double)mid  ) ;
                if ( check > h ) break ;
            }

            if ( check <= h ) 
            {
                ans = mid ;
                high = mid - 1 ;
            }
            else low = mid + 1 ;
        }
        return ans ;
    }
};