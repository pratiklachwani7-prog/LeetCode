class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> mini(n);
        mini[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=(nums[i]<mini[i+1])?nums[i]:mini[i+1];
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            if(maxi<nums[i])maxi=nums[i];
            if(maxi-mini[i]<=k)return i;
        }
        return -1;
    }
};