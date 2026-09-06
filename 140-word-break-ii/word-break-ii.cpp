class Solution {
public:
    void solve( string s, vector<string>& wordDict , vector<string>& res , string temp , int idx)
    {
        if ( idx == s.size() ) 
        {
            temp.pop_back() ;
            res.push_back( temp ) ;
            return ;
        }
        string temp2 = "" ;
        string tempDup = temp ;
        for ( int i = idx ; i < s.size() ; i++ )
        {
            temp2 += s[i] ;
            if (find( wordDict.begin() , wordDict.end() , temp2 ) != wordDict.end() )
            {
                temp += temp2 ;
                temp.push_back(' ') ;
                solve( s , wordDict , res , temp , i+1 ) ;
                temp = tempDup ;
            }
        }
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> res ;
        solve( s , wordDict , res , "" , 0 ) ;
        return res ;
    }
};