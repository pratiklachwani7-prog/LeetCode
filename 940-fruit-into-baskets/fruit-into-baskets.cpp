class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int i = 0 , j = 0 , count = 0 , temp = 0 , ans = 0 , n = fruits.size() ;
        unordered_map<int,int> mp ;

        while ( j < n )    
        {
            mp[fruits[j]]++;
            if ( mp[fruits[j]] == 1 ) count++;
            temp++;

            if ( count <= 2 )
            {
                ans = max(ans , temp ) ;
                j++;
            }
            else //count > 2
            {
                while ( count > 2 )
                {
                    mp[fruits[i]]--;
                    if ( mp[fruits[i]] == 0) count--;
                    temp-- ;
                    i++;
                }
                j++;
            }
        }
        return ans ;
    }
};