class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        long long n = bloomDay.size() ;
        if (1LL * m * k > bloomDay.size()) return -1;
        
        int mini = INT_MAX , maxi = INT_MIN ;
        for ( int i = 0 ; i < n ; i++ ) 
        {
            mini = min( bloomDay[i] , mini ) ;
            maxi = max( bloomDay[i] , maxi ) ;
        }

        int low = mini , high = maxi , ans = -1 ;

        while ( low <= high )
        {
            int mid = low + ( high - low ) / 2  , count = 0 , bou = 0 ;
            for ( int i = 0 ; i < n ; i++ )
            {
                if ( bloomDay[i] <= mid ) count++;
                else
                {
                    bou += ( count/k ) ;
                    count = 0 ;
                }
            }
            bou += (count/k) ;

            if ( bou >= m )
            {
                ans = mid ;
                high = mid - 1 ;
            }
            else low = mid + 1 ;
        }
        return ans ;
    }
};