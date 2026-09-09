class Solution {
public:
    long long noOfCommaInRange(long long x)
    {
        if ( x == 0 || x == 1 || x == 2 || x == 3 ) return 0 ;

        long long ans = ( (x-1)/3 * 9 * pow(10,x-1) )  + noOfCommaInRange(x-1);

        return ans ;
    }
    long long countCommas(long long n) 
    {

        long long x = to_string(n).length()  ;
        cout<<x;
        if ( x < 4 ) return 0 ;
        long long currCommas = (x-1)/3 * ( n - pow(10,x-1) + 1 ) ;
        return currCommas + noOfCommaInRange(x-1) ;

    }
};