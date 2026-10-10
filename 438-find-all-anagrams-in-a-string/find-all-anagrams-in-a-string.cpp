class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_map<char , int> freq ;

        for ( auto& x : p ) freq[x]++;

        vector<int> ans ; 
        int count = freq.size() ;
        int k = p.size() ;
        int i = 0 , j = 0 ; 

        while ( j < s.size() )
        {
            if ( freq.find( s[j] ) != freq.end() )
            {
                freq[s[j]]--;
                if ( freq[s[j]] == 0 ) count--;
            }

            if ( j - i + 1 < k ) j++;
            else
            {
                if ( count == 0 ) ans.push_back( i ) ;

                if ( freq.find( s[i] ) != freq.end() )
                {
                    freq[s[i]]++;
                    if ( freq[s[i]] == 1 ) count++;
                }
                i++;
                j++;
            }
        }
        
        return ans ;
    }
};