class Solution {
public:
    int find_pivot(auto& nums){
        int l=0,r=nums.size()-1;
        int ans=nums.size()-1;
        if(nums[l]<nums[r])
            return ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(l==mid) return mid;
            if(nums[mid]>nums[l]){
                l=mid;
            }else
                r=mid;
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int pivot=find_pivot(nums);
        int n=nums.size();
        int l=0,r=pivot;
        if(target<nums[0])
            l=pivot+1,r=n-1;
        cout<<l<<"  "<<r<<endl;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};