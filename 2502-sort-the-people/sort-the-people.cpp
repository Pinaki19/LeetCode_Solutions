class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> ind(names.size());
        iota(ind.begin(),ind.end(),0);
        sort(ind.begin(),ind.end(),[&heights](int i1,int i2){
            if(heights[i1]==heights[i2]) return false;
            return heights[i1]>heights[i2];
        });
        vector<string> ans;
        for(int i=0;i<names.size();i++)
            ans.push_back(names[ind[i]]);
        return ans;
    }
};