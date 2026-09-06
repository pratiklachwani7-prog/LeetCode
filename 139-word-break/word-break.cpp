class Solution {
public:
    vector<int> t ;
    bool solve(string s, vector<string>& wordDict , int idx )
    {
        if ( idx == s.size() ) return t[idx] = true ;
        if ( t[idx] != -1 ) return t[idx] ;
        string temp ;
        for ( int i = idx ; i < s.size() ; i++ )
        {
            temp += s[i] ;
            if ( find( wordDict.begin() , wordDict.end() , temp ) != wordDict.end() )
            {
                int ans = solve(s,wordDict,i+1) ;
                if ( ans ) return t[idx] = ans ;
            }
        }
        return t[idx] = false ;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        t = vector<int>( s.size()  + 1, -1 ) ;
        return solve( s , wordDict , 0  ) ;
    }
};