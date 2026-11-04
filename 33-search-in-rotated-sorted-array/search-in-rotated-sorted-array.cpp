class Solution {
public:
    int search(vector<int>& arr, int target) 
    {
        int low = 0 , high = arr.size() - 1 ;

        while ( low <= high )    
        {
            int mid = high + ( low - high ) / 2 ;

            if ( arr[mid] == target ) return mid ;

            if ( arr[low] <= arr[mid] ) //left side is sorted and i will search in the left side
            {
                if ( arr[low] <= target && target <= arr[mid] ) high = mid - 1 ; 
                else low = mid + 1 ; 
            }

            else //right side is sorted and i will search in the right side
            {
                if ( arr[mid] <= target && target <= arr[high] ) low = mid + 1 ;
                else high = mid - 1 ;
            }
        }
        return -1 ;
    }
};