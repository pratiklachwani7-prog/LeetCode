class Solution {
public:
    int mySqrt(int x) 
    {
        int low = 0 , high = x , ans = 0 ;

        while ( low <= high ) 
        {
            long long mid = low + ( high - low ) / 2 ;

            if ( mid * mid > x ) high = mid - 1 ;
            else
            {
                ans = mid ;
                low = mid + 1 ;
            }
        }   
        return ans ;
    }
};