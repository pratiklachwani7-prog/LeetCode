class Solution {
public:
    int sumCounts(vector<int>& nums) 
    {
        int ans = 0 ;
        for ( int j = 0 ; j < nums.size() ; j++ )
        {
            vector<int> freq(101,0) ;
            int distinct = 0 ;
            for ( int i = j ; i < nums.size() ; i++ )
            {
                if ( freq[nums[i]] == 0 )
                {
                    freq[nums[i]]++;
                    distinct++;
                }
                else freq[nums[i]]++ ;

                ans += (distinct * distinct) ;
            }
            freq = vector<int>( 101 , 0 ) ;
            distinct = 0 ;
        }
        return ans ;
    }
};