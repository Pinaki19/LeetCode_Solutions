class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(0);
        string first="ab",second="ba";
        if(x<y){
            swap(first,second);
            swap(x,y);
        }

        int ans=0;
        int pos=s.find(first);
        while(pos!=string::npos){
            ans+=x;
            s.erase(s.begin()+pos,s.begin()+pos+2);
            pos=s.find(first,max(pos-1,0));
        }

        pos=s.find(second);
        while(pos!=string::npos){
            ans+=y;
            s.erase(s.begin()+pos,s.begin()+pos+2);
            pos=s.find(second,max(pos-1,0));
        }
        return ans;
    }
};