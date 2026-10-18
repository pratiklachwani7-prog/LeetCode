class Solution {
public:
    char ans ;
    void operation(string& s , int k)
    {
        if ( s.size() > k ) 
        {
            ans = s[k-1] ;
            return ;
        }
        string temp = s  ;
        string dup = s ;
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            char ch = (dup[i] - 'a' + 1) % 26 + 'a' ; 
            dup[i] = ch ;
        }
        string swapped = temp + dup ;
        operation(swapped,k) ;
    }
    char kthCharacter(int k) 
    {
        string str = "a" ;
        operation(str,k) ; 
        return ans ;
    }
};