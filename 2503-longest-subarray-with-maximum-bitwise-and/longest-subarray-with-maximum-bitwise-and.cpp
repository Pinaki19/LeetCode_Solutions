class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int cur=0;
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(nums[i]==maxVal)
                temp.push_back(i);
        }
        vector<bool> visited(n,false);
        for(int i:temp){
            if(visited[i]) continue;
            int l=i,r=i;
            visited[i]=true;
            int curAnd=nums[i];
            while(l>0){
                int left=nums[l-1];
                bool allSet=true;
                for(int i=0;i<32;i++){
                    if((curAnd>>i)&1){
                        if(((left>>i)&1)==0){
                            allSet=false;
                            break;
                        }
                    }
                }
                if(!allSet) break;
                visited[l]=true;
                l--;
            }
            while(r<n-1){
                int right=nums[r+1];
                bool allSet=true;
                for(int i=0;i<32;i++){
                    if((curAnd>>i)&1){
                        if(((right>>i)&1)==0){
                            allSet=false;
                            break;
                        }
                    }
                }
                if(!allSet) break;
                visited[r]=true;
                r++;
            }
            ans=max(ans,r-l+1);
        }

        return ans;
    }
};