class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int i = 0 , j = 0 , count = 0 , n = s.size() , ans = 0 ; 
        unordered_map<char,int> mp ;
        
        while ( j < n )
        {
            mp[s[j]]++;
            if ( mp[s[j]] == 1 ) count++;
            
            if ( count > j-i+1 ) j++;
            else if ( count == j - i + 1 ) 
            {
                ans = max(ans,j-i+1) ;
                j++;
            }
            else //count < j-i+1
            {
                while ( count < j-i+1 ) 
                {
                    mp[s[i]]--;
                    if ( mp[s[i]] == 0 ) count--;
                    i++;
                }
                j++;
            }
        }
        return ans ;     
    }
};