class Solution {
public:
    int passwordStrength(string password) 
    {
        int n = password.size() ;
        int ans = 0 ;
        unordered_map<int,int> freq ;
        for ( auto& x : password ) freq[x]++;

        for ( auto& p : freq )
        {
            if ( isdigit( p.first ) ) ans += 3 ;
            else if ( isalpha( p.first ) && islower( p.first ) )  ans += 1 ;
            else if ( isalpha( p.first ) && isupper( p.first ) )  ans += 2 ;
            else ans += 5 ; 
        }
        return ans ;
    }
};