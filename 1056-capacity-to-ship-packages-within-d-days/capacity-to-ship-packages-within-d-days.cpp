class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int maxi = INT_MIN , sum = 0 ;

        for ( auto& x : weights ) 
        {
            maxi = max(x,maxi) ;
            sum += x ;
        }

        int low = maxi , high = sum  ;
        while ( low <= high )
        {
            int mid = low + ( high - low ) / 2 ; 

            int temp = 0 , i = 0 , requiredDays = 1 ;
            while ( i < weights.size() )
            {
                if ( temp + weights[i] > mid )
                {
                    requiredDays++ ;
                    temp = 0;
                }
                else 
                {
                    temp += weights[i] ;
                    i++;
                }
            }

            if ( requiredDays > days ) low = mid + 1 ;
            else 
            {
                high = mid - 1 ; 
            }
        }
        return low;


    }
};