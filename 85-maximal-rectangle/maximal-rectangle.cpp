class Solution {
public:
    int maxHistogram( vector<int> arr )
    {
        int n = arr.size() ;

        //nearest smallest on left
        stack< pair<int,int> > st ;
        vector<int> left(n,0) ;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( st.size() == 0 ) left[i] = -1 ;
            else
            {
                if ( st.top().first < arr[i] ) left[i] = st.top().second ;
                else
                {
                    while ( st.size() > 0 && st.top().first >= arr[i] ) st.pop();

                    if ( st.size() == 0 ) left[i] = -1 ;
                    else left[i] = st.top().second ;
                }
            }
            st.push( {arr[i] , i} ) ;
        }

        //nearest greatest at right
        while( st.size() > 0 ) st.pop() ;
        vector<int> right(n,0) ;
        for ( int i = n - 1 ; i >= 0 ; i-- )
        {
            if ( st.size() == 0 ) right[i] = n ;
            else
            {
                if ( st.top().first < arr[i] ) right[i] = st.top().second ;
                else
                {
                    while ( st.size() > 0 && st.top().first >= arr[i] ) st.pop() ; 

                    if ( st.size() == 0 ) right[i] = n ;
                    else right[i] = st.top().second ;
                }
            }
            st.push( {arr[i] , i} ) ;
        }

        int mx = INT_MIN ;
        for ( int i = 0 ; i < n ; i++ )
        {
            int area = (right[i] - left[i] - 1 ) * arr[i] ;
            mx = max( mx , area ) ;
        }
        return mx ;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<int> v(m,0) ;
        for ( int j = 0 ; j < m ; j++ ) v[j] = matrix[0][j] -'0'  ;

        int mx = maxHistogram(v) ;
        for ( int i = 1 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < m ; j++ )
            {
                if ( matrix[i][j] != '0' ) v[j] = (v[j] + matrix[i][j] - '0') ;
                else v[j] = 0 ;
            }
            mx = max( mx , maxHistogram(v) ) ;
        }

        return mx ;
    }
};