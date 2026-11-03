class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> mp ;
        for ( auto x : t ) mp[x]++;
        int i = 0 , j = 0 , n = s.size() , count = mp.size() , ans = INT_MAX , start = 0 ;

        while( j < n )
        {
            if ( mp.find(s[j]) != mp.end() )
            {
                mp[s[j]]--;
                if ( mp[s[j]] == 0 ) count--;
            }

            if ( count == 0 )
            {
                while ( count == 0 )
                {
                    if ( ans > j-i+1 )
                    {
                        ans = j-i+1 ;
                        start = i ;
                    }
                    if ( mp.find(s[i]) != mp.end() )
                    {
                        mp[s[i]]++;
                        if ( mp[s[i]] == 1 ) count++;
                    }
                    i++;
                }
            }
            j++;
        }
        
        if ( ans != INT_MAX ) return s.substr(start,ans) ;
        else return "" ;
    }
};