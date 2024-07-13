class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios_base::sync_with_stdio(0);
        vector<pair<int,int>> pos_ind;
        int n=positions.size();
        for(int i=0;i<n;i++)
            pos_ind.push_back({positions[i],i});

        sort(pos_ind.begin(),pos_ind.end());
       
        vector<pair<int,int>> ans_temp;
        auto will_collide=[&](int cur)->bool{
            if(ans_temp.empty()||cur==-1) return false;
            int prev=ans_temp.back().first;
            char prev_dir=directions[prev],cur_dir=directions[cur];
            if(positions[cur]<positions[prev])
                swap(prev_dir,cur_dir);
            return prev_dir=='R' && cur_dir=='L';
        };
        bool insert;
        int damage=0;
        for(auto [pos,ind]:pos_ind){
           if(will_collide(ind)){
                insert=false;
                damage=0;
                while(will_collide(ind)){
                    auto& [prev_ind,last]=ans_temp.back();
                    if(last>healths[ind]-damage){
                        last-=1;
                        ind=-1;
                    }else if(last<healths[ind]-damage){
                        insert=true;
                        damage++;
                        ans_temp.pop_back();
                    }else{
                        ans_temp.pop_back();
                        ind=-1;
                    }
                }
                if(insert && ind>=0)
                    ans_temp.push_back({ind,healths[ind]-damage});
           }else
             ans_temp.push_back({ind,healths[ind]});
        }
        sort(ans_temp.begin(),ans_temp.end());
        vector<int> ans;
        
        for(auto& [ind,val]:ans_temp)
            ans.push_back(val);
        return ans;
    }
};