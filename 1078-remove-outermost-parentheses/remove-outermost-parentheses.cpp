class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int count = 0 ; 
        string ans ;
        string temp ;
        for ( int i = 0 ; i < s.size() ; i++ )    
        {
            temp += s[i] ;
            if ( s[i] == '(' ) count++ ;
            else count--;

            if ( count == 0 )
            {
                for ( int i = 1 ; i < temp.size() - 1  ; i++ ) ans += temp[i] ;
                temp = "" ;
            }
        }
        return ans ;
    }
};