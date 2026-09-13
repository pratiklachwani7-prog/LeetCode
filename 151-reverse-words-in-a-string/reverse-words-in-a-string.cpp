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

            string temp ;
            while ( i >= 0 && s[i] != ' ' ) 
            {
                temp += s[i] ;
                i--;
            }

            reverse( temp.begin() , temp.end() ) ;
            ans = ans + temp + " " ;
        }
        ans.pop_back() ;
        return ans ;


    }
};