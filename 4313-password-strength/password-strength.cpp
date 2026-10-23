class Solution {
public:
    int passwordStrength(string password) 
    {
        int n = password.size() ;
        vector<int> freq( 128 , 0  ) ;
        for ( int i = 0 ; i < n ; i++ )
        {
            int ascii = password[i] ;
            freq[ ascii ]++ ;
        }

        int ans = 0 ;
        for ( int i = 0 ; i < 128 ; i++ )
        {
            if ( freq[i] != 0 )
            {
                char temp = i ;
                if ( isdigit( temp ) ) ans += 3 ;
                else if ( isalpha( temp ) && islower( temp ) )  ans += 1 ;
                else if ( isalpha( temp ) && isupper( temp ) )  ans += 2 ;
                else ans += 5 ; 
            }
        }
        return ans ;
    }
};