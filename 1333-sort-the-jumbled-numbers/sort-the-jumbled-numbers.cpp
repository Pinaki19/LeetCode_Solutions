class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //ios_base::sync_with_stdio(0);
        sort(nums.begin(),nums.end(),[&mapping](int i,int j){
            if(i==j) return false;
            string is=to_string(i);
            string js=to_string(j);
            while(is.size() && mapping[is[0]-'0']==0)
                is.erase(is.begin());
            while(js.size() && mapping[js[0]-'0']==0)
                js.erase(js.begin());
            //cout<<is<<"  "<<js<<endl;
            if(is.size()<js.size()) return true;
            if(js.size()<is.size()) return false;
            for(int i=0;i<is.size();i++){
                int k1=is[i]-'0',k2=js[i]-'0';
                if(mapping[k1]==mapping[k2]) continue;
                if(mapping[k1]<mapping[k2])
                    return true;
                else
                    return false;
            }
            return false;
        });
        return nums;
    }
};