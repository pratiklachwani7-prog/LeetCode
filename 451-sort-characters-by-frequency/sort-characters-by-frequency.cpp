class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> temp ;
        for ( auto& x : s ) temp[x]++;

        vector< pair<char,int> > freq ;
        for ( auto& p : temp ) freq.push_back( {p.first , p.second} ) ;

        sort( freq.begin() , freq.end() , [](pair<char,int> a , pair<char,int> b )
                                            {
                                                return a.second > b.second ;
                                            }  ) ;

        string ans = "" ;

        for ( auto& v : freq )
        {
            string tet = string(v.second , v.first) ;
            ans += tet ;
        }
        return ans ;
    }
};