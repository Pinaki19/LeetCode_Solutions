class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        ios_base::sync_with_stdio(0);
        for(int i=0;i<n;i++)
            if(group[i]==-1)
                group[i]=m++;

        vector<vector<int>> after_groups(m,vector<int>());
        vector<set<int>> group_items(m,set<int>());
        vector<int> group_indeg(m,0);
        vector<int> indeg(n,0);
        vector<int> ans_groups,ans;
        vector<vector<int>> within_group(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int item:beforeItems[i]){
                if(group[i]!=group[item]  ){
                    after_groups[group[item]].push_back(group[i]);
                    group_indeg[group[i]]++;
                }else{
                    indeg[i]++;
                    within_group[item].push_back(i);
                }   
            }
            group_items[group[i]].insert(i);
        }

        queue<int> q;
        for(int i=0;i<m;i++){
            if(group_indeg[i]==0)
                q.push(i);
        }
    
        while(q.size()){
            int gr_num=q.front();q.pop();
            for(int i:after_groups[gr_num]){
                group_indeg[i]--;
                if(group_indeg[i]==0)
                    q.push(i);
            }
            ans_groups.push_back(gr_num);
        }
        if(ans_groups.size()!=m) return {};

        auto solve=[&](int group_num)->bool{
            int c=0;
            for(int i:group_items[group_num]){
                if(indeg[i]==0)
                    q.push(i);
            }
            while(q.size()){
                int item=q.front();q.pop();
                for(int i:within_group[item]){
                    indeg[i]--;
                    if(indeg[i]==0)
                        q.push(i);
                }
                ans.push_back(item);
                c++;
            }
            return c==group_items[group_num].size();
        };
        bool res;
        for(int i:ans_groups){
            res=solve(i);
            if(!res) return {};
        }
        return ans;
    }
};