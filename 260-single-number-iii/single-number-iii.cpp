class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorSum = 0;
        
        for (int num : nums) {
            xorSum ^= num;
        }
        long mask = xorSum & -xorSum;
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & mask) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};