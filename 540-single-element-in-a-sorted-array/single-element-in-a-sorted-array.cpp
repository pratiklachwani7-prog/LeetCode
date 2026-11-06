class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) 
    {
        int n = arr.size() ;
        if ( n == 1 ) return arr[0] ;
        if ( arr[0] != arr[1] ) return arr[0] ;
        else if ( arr[n-1] != arr[n-2] ) return arr[n-1] ;

        int low = 1 , high = n - 2 ;

        while ( low <= high )    
        {
            int mid = low + ( high - low ) / 2 ;

            if ( arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1] ) return arr[mid] ;

            if ( mid % 2 == 1 ) 
            {
                if ( arr[mid] == arr[mid-1] ) low = mid + 1 ;
                else if ( arr[mid] == arr[mid+1] ) high = mid - 1 ;
            }
            else
            {
                if ( arr[mid] == arr[mid-1] ) high = mid - 1 ;
                else if ( arr[mid] == arr[mid+1] ) low = mid + 1 ;
            }
        }

        return -1 ;    
    }
};