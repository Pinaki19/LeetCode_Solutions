class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        while(r<n){
            while(dq.size() && nums[r]>dq.back())
                dq.pop_back();
            dq.push_back(nums[r]);
            if(r-l+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[l])
                    dq.pop_front();
                l++;
            }
            r++;
        }

        return ans;
    }
};