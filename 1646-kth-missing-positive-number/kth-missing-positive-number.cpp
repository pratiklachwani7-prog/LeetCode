class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        map<int , int > mp ;
        int maxi = INT_MIN ;

        for ( int i = 0 ; i < arr.size() ; i++) maxi = max( maxi , arr[i] ) ;

        for ( int i = 1 ; i < maxi + k + 3 ; i++ ) mp[i]++;

        for ( auto& x : arr ) mp[x]++;

        for ( auto p : mp )
        {
            if ( p.second == 1 ) k--;

            if ( k == 0 ) return p.first ;
        }
        return -1 ;
    }
};