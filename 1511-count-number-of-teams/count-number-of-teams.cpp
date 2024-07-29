class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<vector<int>> mp(n,vector<int>());
        vector<vector<int>> mp2(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i])
                    mp[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i])
                    mp2[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j:mp[i]){
                ans+=mp[j].size();
            }
        }
        for(int i=0;i<n;i++){
            for(int j:mp2[i]){
                ans+=mp2[j].size();
            }
        }
        return ans;
    }

};