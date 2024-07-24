class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //ios_base::sync_with_stdio(0);
        sort(nums.begin(),nums.end(),[&mapping](int i,int j){
            if(i==j) return false;
            string is=to_string(i);
            string js=to_string(j);
            int p=0,q=0;
            while(p<is.size() && mapping[is[p]-'0']==0)
                p++;
            while(q<js.size() && mapping[js[q]-'0']==0)
                q++;
            //cout<<is<<"  "<<js<<endl;
            if(is.size()-p<js.size()-q) return true;
            if(js.size()-q<is.size()-p) return false;
            for(;p<is.size() && q<js.size() ;p++,q++){
                int k1=is[p]-'0',k2=js[q]-'0';
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