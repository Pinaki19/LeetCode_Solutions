class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,prev=-1;
        stack<int> st;
        for(int i:nums){
            if(i==prev){
               st.push(i);
            }else{
                prev++;
                while(st.size() && i!=prev){
                    ans+=prev-st.top();
                    st.pop();
                    prev++;
                }
                prev=i;
            }
            prev=max(prev,i);
        }
        prev++;
        while(st.size()){
            ans+=prev-st.top();
            st.pop();
            prev++;
        }
        return ans;
        
    }
};