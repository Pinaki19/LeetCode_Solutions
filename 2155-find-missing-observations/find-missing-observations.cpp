class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int total=m+n;
        int sum=total*mean;
        int current_sum=accumulate(rolls.begin(),rolls.end(),0);
        int rest=sum-current_sum;

        if(rest<n || rest>n*6 )
            return {};
        int t=rest/n;
        int rem=rest%n;
        vector<int> ans(n,t);
        for(int &i:ans){
            if(rem==0) break;
            rem--;
            i++;
        }
        return ans;
    }
};