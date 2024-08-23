class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> mx(n);
        mx[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            mx[i]=max(height[i+1],mx[i+1]);
        int lmax=height.front();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(0,min(lmax,mx[i])-height[i]);
            lmax=max(lmax,height[i]);
        }
        return ans;
    }
};