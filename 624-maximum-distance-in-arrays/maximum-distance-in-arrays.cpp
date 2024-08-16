class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=0;
        multiset<int> maxes;
        set<int> mins;
        for(auto& v:arrays){
            maxes.insert(v.back());
            mins.insert(v.front());
        }

        for(auto& v:arrays){
            int mx=v.back();
            int mn=v.front();
            int last=*maxes.rbegin();
            if(mx==last){
                auto pos=next(maxes.rbegin());
                int p= pos!=maxes.rend()? *pos:mn;
                ans=max(ans,abs(p-mn));
            }else
                ans=max(ans,abs(last-mn));
        }

        return ans;
    }
};