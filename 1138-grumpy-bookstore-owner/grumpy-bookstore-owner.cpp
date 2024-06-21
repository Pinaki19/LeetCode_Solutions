class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int l=0,r=0;
        int maxBenifit=0,benifit=0;
        int n=grumpy.size();
        while(r<n){
            while(r<n && r-l<minutes){
                if(grumpy[r]) benifit+=customers[r++];
                else ans+=customers[r++];
            }
            maxBenifit=max(maxBenifit,benifit);
            if(grumpy[l]) benifit-=customers[l];
            l++;
        }
        return ans+maxBenifit;
    }
};