class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first="ab",second="ba";
        if(x<y){
            swap(first,second);
            swap(x,y);
        }
        auto match=[&s](int i,string t)->bool{
            if(i>=s.size()-1||t[0]!=s[i]) return false;
            return s[i]==t[0] && s[i+1]==t[1];
        };

        int ans=0;
        int i=0;
        while(i<s.size()){
            if(match(i,first)){
                int l=i,r=i+1;
                int cnt=0;
                while(l>=0 && r<s.size() && s[l]==first[0] && s[r]==first[1])
                    l--,r++,cnt++;
                ans+=cnt*x;
                s.erase(s.begin()+i-cnt+1,s.begin()+i+cnt+1);
                i=max(0,i-cnt);
            }else
                i++;
        }

        i=0;
        while(i<s.size()){
            if(match(i,second)){
                int l=i,r=i+1;
                int cnt=0;
                while(l>=0 && r<s.size() && s[l]==second[0] && s[r]==second[1])
                    l--,r++,cnt++;
                ans+=cnt*y;
                s.erase(s.begin()+i-cnt+1,s.begin()+i+cnt+1);
                i=max(0,i-cnt);
            }else
                i++;
        }

        return ans;
    }
};