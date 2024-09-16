class Solution {
public:
    Solution(){
        srand(time(0));
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums.front();
        vector<int> gr;
        vector<int> lt;
        vector<int> eq;
        int r_ind=rand()%nums.size();
        int pivot=nums[r_ind];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot)
                gr.push_back(nums[i]);
            else if(nums[i]<pivot)
                lt.push_back(nums[i]);
            else
                eq.push_back(nums[i]);
        }
        int num_lt=lt.size();
        int num_gr=gr.size();
        int num_eq=eq.size();
        if(k<=num_gr)
            return findKthLargest(gr,k);
        else if(k>num_gr+num_eq)
            return findKthLargest(lt,k-num_gr-num_eq);
        else 
            return eq.front();
    }
};