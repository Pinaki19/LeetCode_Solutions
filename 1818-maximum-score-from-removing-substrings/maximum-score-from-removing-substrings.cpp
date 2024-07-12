class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a='a',b='b';
        if(x<y){
            swap(x,y);
            swap(a,b);
        }
        int ans=0;
        string temp;
        for(char c:s){
            if(temp.size() && temp.back()==a && c==b){
                temp.pop_back();
                ans+=x;
            }else
                temp.push_back(c);
        }
        
        s=temp;
        temp="";
        for(char c:s){
            if(temp.size() && temp.back()==b && c==a){
                temp.pop_back();
                ans+=y;
            }else
                temp.push_back(c);
        }

        return ans;
    }
};