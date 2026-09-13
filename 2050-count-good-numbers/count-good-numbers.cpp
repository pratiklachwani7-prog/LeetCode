class Solution {
public:
    long long power( long long base , long long power , long long mod )
    {
        long long ans = 1 ;

        while ( power > 0  )
        {
            if ( power & 1 ) ans = ( ans * base ) % mod ;

            base = ( base * base ) % mod ;

            power >>= 1 ;
        }

        return ans ;
    }
    int countGoodNumbers(long long n) 
    {
        long long mod = (int)(pow(10,9) + 7) * 1LL ;

        long long even = ( n + 1 ) / 2 ;
        long long odd = n / 2 ;

        long long evenPower = power( 5 , even , mod ) ;
        long long oddPower = power( 4 , odd , mod ) ;

        return ( evenPower * oddPower ) % mod ;
    }
};