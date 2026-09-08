class Solution {
public:
    int noOfCommaInRange(int x)
    {
        if ( x == 0 || x == 1 || x == 2 || x == 3 ) return 0 ;

        int ans = ( (x-1)/3 * 9 * pow(10,x-1) )  + noOfCommaInRange(x-1);

        return ans ;
    }
    int countCommas(int n) 
    {

        int x = floor(log10(n)) + 1 ;
        if ( x < 4 ) return 0 ;
        int currCommas = (x-1)/3 * ( n - pow(10,x-1) + 1 ) ;
        return currCommas + noOfCommaInRange(x-1) ;

    }
};