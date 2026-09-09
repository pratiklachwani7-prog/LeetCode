class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        stack<int> st ; 
        int n = arr.size() ;
        for ( int i = n - 1 ; i >= 0 ; i-- )    
        {
            int temp = arr[i] ; 

            if ( st.size() == 0 ) arr[i] = -1 ;
            else arr[i] = st.top() ;

            if ( st.size() == 0 || temp > st.top() ) st.push( temp ) ;
        }
        return arr ;
    }
};