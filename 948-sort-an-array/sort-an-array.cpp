class Solution {
public:
    int partition(int l,int r,auto& nums){
        int j=l-1;
        int sz=r-l+1;
        int piv=l+rand()%sz;
        swap(nums[piv],nums[r]);
        int pivot=nums[r];
        for(int i=l;i<r;i++){
            if(nums[i]<pivot){
                j++;
                swap(nums[i],nums[j]);
            }
        }
        j++;
        swap(nums[r],nums[j]);
        return j;
    }
    void quick_sort(int l,int r,auto& nums){
        if(l<r){
            int pos=partition(l,r,nums);
            quick_sort(l,pos-1,nums);
            quick_sort(pos+1,r,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quick_sort(0,nums.size()-1,nums);
        return nums;
    }
};