class Solution {
public:
    string fractionAddition(string exp) {
        int n=exp.size();
        if(n<=4){
            if(exp[0]=='+')
                exp=exp.substr(1);
            return exp;
        }
        int tot=1;
        int Gcd=0;
        int i=0;
        while(i<n){
            if(exp[i]=='/'){
                int val=0;
                int j=i+1;
                int mult=1;
                while(j<n && (exp[j]!='+' && exp[j]!='-')){
                    int p=exp[j]-'0';
                    val=val*mult+p;
                    j++;
                    mult*=10;
                }
                tot*=val;
                Gcd=gcd(Gcd,val);
            }
            i++;
        }
        if(Gcd==0) return exp;

        int Lcm=tot/Gcd;
        int sum=0;
        i=0;
        while(i<n){
            if(exp[i]=='/'){
                int j=i-1;
                int mult=1;
                int nu=0;
                while(j>=0 && (exp[j]!='+' && exp[j]!='-')){
                    int p=exp[j]-'0';
                    nu=mult*p+nu;
                    j--;
                    mult*=10;
                }
                int sign= j>=0 && exp[j]=='-'? -1:1;
                int de=0;
                j=i+1;
                mult=1;
                while(j<n && (exp[j]!='+' && exp[j]!='-')){
                    int p=exp[j]-'0';
                    de=de*mult+p;
                    j++;
                    mult*=10;
                }
                sum+= (Lcm/de) *nu*sign;
            }
            i++;
        }
        //cout<<sum<<"  "<<Lcm<<endl;
        
        string ans="";
        if(sum<0) ans+='-',sum*=-1;
        int G=gcd(sum,Lcm);
        int t1=sum/G;
        int t2=Lcm/G;
        return ans+to_string(t1)+'/'+to_string(t2);
    }
};