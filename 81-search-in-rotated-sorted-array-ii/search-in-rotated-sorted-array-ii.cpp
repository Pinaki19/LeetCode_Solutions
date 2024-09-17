class Solution {
public:
    int find_pivot(auto& nums){
        int l=0,r=nums.size()-1;
        int ans=r;
        while(l<r){
            if(nums[l]<nums[r])
                return r;
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[l])
                l=mid;
            else if(nums[mid]<nums[l])
                r=mid-1;
            else{
              while(l<r){
                if(nums[l]>nums[l+1]) return l;
                l++;
              }
            }
        }
        return l;
    }
    bool search(vector<int>& nums, int target) {
        int pivot=find_pivot(nums);
        int l=0,r=pivot;
        if(target<nums[l])
            l=pivot+1,r=nums.size()-1;
        cout<<pivot<<endl;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return true;
            if(l==r) break;
            if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};