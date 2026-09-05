class Solution {
public:
    int mini( vector<int>& nums , int start , int end )
    {
        int temp = INT_MAX ;
        for ( int i = start ; i <= end ; i++ )
        {
            if ( temp > nums[i] ) temp = nums[i] ;
        }
        return temp;
    }
    int maxi( vector<int>& nums , int start , int end )
    {
        int temp = INT_MIN ;
        for ( int i = start ; i <= end ; i++ )
        {
            if ( temp < nums[i] ) temp = nums[i] ;
        }
        return temp;
    }
    int firstStableIndex(vector<int>& nums, int k) 
    {
        if ( nums.size() == 1 ) 
        {
            return 0 ;
        }
        int ans = INT_MAX ;
        int ansIdx = -1 ;
        int n = nums.size() ;
        for ( int i = 0 ; i < n ; i++ )
        {
            int score = maxi( nums , 0 , i ) - mini( nums , i , n - 1  ) ;
            if ( score <= k )
            {
                return ansIdx = i ;
            }
        }
        return ansIdx ;
    }
};