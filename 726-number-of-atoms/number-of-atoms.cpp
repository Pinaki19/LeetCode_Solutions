class Solution {
public:
    string countOfAtoms(string formula) {
        function<int(int,map<string,int>&)> solve=[&s=formula,&solve](int i,map<string,int>& mp)->int{
            if(i>=s.size()) return s.size();
            map<string,int> c;
            int last=i;
            if(s[i]=='('){
                last=solve(i+1,c);
            }else if(s[i]==')'){
                int j=i+1;
                int mult=0;
                while(j<s.size() && isdigit(s[j]))
                    mult=mult*10+(s[j++]-'0');
                mult=mult==0? 1:mult;
                for(auto& [_,v]:mp) v*=mult;
                return j;
            }else{
                string t="";
                t+=s[i++];
                while(i<s.size() && s[i]>='a' && s[i]<='z')
                    t+=s[i++];
                int mult=0;
                while(i<s.size() && isdigit(s[i]))
                    mult=mult*10+(s[i++]-'0');
                
                mult=mult==0? 1:mult;
                mp[t]+=mult;
                last=i;
            }
            for(auto [k,v]:c)
                mp[k]+=v;
            //cout<<"At : "<<i<<" Last: "<<last<<endl;
            return solve(last,mp);
        };

        map<string,int> ans;
        solve(0,ans);
        string s="";
        for(auto& [k,v]:ans){
            s+=k;
            if(v>1)
                s+=to_string(v);
        }
        return s;
    }
};