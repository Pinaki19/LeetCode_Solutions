class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> result;
        for(int i=0;i<exp.size();i++){
            char c=exp[i];
            if(c=='+'||c=='-'||c=='*'){
                vector<int> res1=diffWaysToCompute(exp.substr(0,i));
                vector<int> res2=diffWaysToCompute(exp.substr(i+1));
                for(int t1:res1){
                    for(int t2:res2){
                        if(c=='+')
                            result.push_back(t1+t2);
                        else if(c=='-')
                            result.push_back(t1-t2);
                        else
                            result.push_back(t1*t2);
                    }
                }
            }
        }
        if(result.empty())
            result.push_back(stoi(exp));
        return result;
    }
};