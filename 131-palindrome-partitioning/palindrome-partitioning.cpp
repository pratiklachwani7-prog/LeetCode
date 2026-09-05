class Solution {
public:
    bool isPalindrome( string temp2 )
    {
        if ( temp2.size() == 1 ) return true ;

        int left = 0 , right = temp2.size() - 1  ;
        while ( left <= right )
        {
            if ( temp2[left] != temp2[right] ) return false ;
            left++;right--;
        }
        return true ;
    }
    void solve( string s , vector< vector<string> >& res , vector<string> temp1 , int idx)
    {
        if ( idx == s.size() )
        {
            res.push_back( temp1 ) ;
            return ;
        }
        string palin = "" ;
        for ( int i = idx ; i < s.size() ; i++ )
        {
            palin.push_back( s[i] ) ;
            if ( isPalindrome(palin) ) 
            {
                temp1.push_back( palin ) ;
                solve( s , res , temp1 , i + 1  ) ;
                temp1.pop_back(  ) ;
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) 
    {
        vector< vector<string> > res ;
        vector<string> temp1 ;
        solve( s , res , temp1 , 0) ;
        return res ;
        
    }
};