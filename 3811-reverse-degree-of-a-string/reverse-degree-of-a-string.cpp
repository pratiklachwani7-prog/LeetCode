class Solution {
public:
    int reverseDegree(string s) 
    {
        int sum = 0 ; 
        for ( int i = 0 ; i < s.length() ; i++ )    
        {
            sum += ( i + 1 ) * ( 26 - (s[i] - 'a') ) ; 
        }
        return sum ; 
    }
};