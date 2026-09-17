class Solution {
public:
    int mirrorDistance(int n) 
    {
        if ( n == 1 ) return 0 ;
        int rev = 0;
        int temp = n ;
        while ( temp )
        {
            rev = rev * 10 +  ( temp % 10 ) ;
            temp = temp/10 ;
        }
        cout<<rev;
        return abs(n-rev) ;
    }
};