class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int& i1,int& i2){
            string s1=to_string(i1);
            string s2=to_string(i2);
            return s1+s2>s2+s1;
        });
        string answer="";
        for(int& i:nums)
            answer+=to_string(i);
        int i=0;
        while(i<answer.size()-1){
            if(answer[i]!='0')
                break;
            i++;
        }
        return answer.substr(i);
    }
};