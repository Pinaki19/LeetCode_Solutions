class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int nums[1001]={0};
        int sum=0;
        for(int i:target)
            nums[i]++,sum++;
        for(int i:arr){
            if(!nums[i])
                return false;
            nums[i]--;
            sum--;
        }

        return sum==0;
    }
};