class Solution {
public:
    string reverseWords(string s) 
    {
        string ans ; 
        int n = s.length() ;
        int i = n - 1 ;

        for ( i ; i >= 0 ; i-- )
        {
            if ( s[i] == ' ' ) continue ;

            int j = i ;
            while ( j >= 0 && s[j] != ' ' ) j-- ;

            if ( !ans.empty() ) ans.push_back(' ') ;
            for ( int k = j + 1 ; k <= i ; k++ ) ans.push_back( s[k] ) ;

            i = j ;
        }
        return ans ;
    }
};