class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans ;
        int i = 0 , j = 0 ;
        list<int> lt ; 
        while ( j < nums.size() )    
        {
            while ( lt.size() > 0 && lt.back() < nums[j] ) lt.pop_back() ;
            lt.push_back(nums[j]) ;

            if ( j - i + 1 < k ) j++;

            else{
                ans.push_back( lt.front() ) ;
                
                if ( lt.front() == nums[i] ) lt.pop_front() ;
                i++;j++;
            }
        }
        return ans ;
    }
};