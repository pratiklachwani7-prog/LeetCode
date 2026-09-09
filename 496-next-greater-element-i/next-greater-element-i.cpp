class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> Dup = nums2 ;
        stack<int> st ;
        for ( int i = nums2.size( ) - 1  ; i >= 0 ; i--)    
        {
            int temp = nums2[i] ;
            if ( st.size() == 0 ) nums2[i] = -1 ;
            else if ( st.size() > 0 && temp < st.top() ) nums2[i] = st.top() ;
            else if ( st.size() > 0 && temp >= st.top() )
            {
                while ( st.size() > 0 && temp >= st.top() )  st.pop() ;

                if ( st.size() == 0 ) nums2[i] = -1 ;
                else nums2[i] = st.top() ;
            }
            st.push( temp ) ;
        }

        for ( int i = 0 ; i < nums1.size() ; i++ )
        {
            int elem = nums1[i] ;
            auto iter = find( Dup.begin() , Dup.end() , elem ) ;
            int idx = iter - Dup.begin() ;

            nums1[i] = nums2[idx] ;
        }
        return nums1 ; 
    }
};