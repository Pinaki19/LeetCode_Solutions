class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int prev=0;
        for(int i:target){
            ans+=max(0,i-prev);
            prev=i;
        }
        return ans;
    }
};