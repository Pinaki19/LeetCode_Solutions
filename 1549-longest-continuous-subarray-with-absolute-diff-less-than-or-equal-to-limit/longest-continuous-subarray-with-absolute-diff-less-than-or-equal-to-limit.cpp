class Solution {
public:
    void show(auto q){
        while(q.size()){
            cout<<q.front()<<"  ";
            q.pop_front();
        }
        cout<<endl;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(0);
        int l=0,r=0;
        int ans=1;
        int n=nums.size();
        deque<int> minq,maxq;
        while(r<n){
            while(minq.size() && nums[r]<minq.back())
                minq.pop_back();
            minq.push_back(nums[r]);
            while(maxq.size() && nums[r]>maxq.back())
                maxq.pop_back();
                maxq.push_back(nums[r]);
                while(minq.size() && maxq.size() && abs(minq.front()-maxq.front())>limit){
                    if(nums[l]==minq.front()) minq.pop_front();
                    if(nums[l]==maxq.front()) maxq.pop_front();
                    l++;
                }
                ans=max(ans,r-l+1);
                r++;
        }
        return ans;
    }
};