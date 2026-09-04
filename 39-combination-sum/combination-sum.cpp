class Solution {
public:
    void solve( vector<int>& candidates, int target , vector<int>& temp , vector<vector<int>>& res , int idx)
    {
        if ( target == 0 )
        {
            if ( find(res.begin() , res.end() , temp ) == res.end() ) res.push_back( temp ) ;
            return ;
        }
        if ( idx == candidates.size() || target < 0 ) return ;
        if ( candidates[idx] <= target )
        {
            temp.push_back( candidates[idx] ) ;
            target = target - candidates[idx] ;
            solve( candidates , target , temp , res , idx) ;
            temp.pop_back() ;
            target = target + candidates[idx] ;
        }
        solve( candidates , target , temp , res , idx + 1 ) ;
        return ;
    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> temp ;
        vector<vector<int>> res ;
        solve( candidates , target , temp , res , 0) ;
        return res ;
    }
};