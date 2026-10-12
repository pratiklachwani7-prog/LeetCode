class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> freq ;
        for ( auto& x : nums ) freq[x]++;

        vector<pair<int,int>> freqFinal( freq.begin() , freq.end() ) ;

        sort( freqFinal.begin() , freqFinal.end() , [](auto& a , auto& b){
            return a.second > b.second ;
        } ) ;
        
        

        vector<int> res ;

        for ( auto iter = freqFinal.begin() ; iter != freqFinal.end() ; iter++ )
        {
            res.push_back( iter->first ) ;
            k--;
            if ( k == 0 ) break ;
        }

        return res ;
    }
};