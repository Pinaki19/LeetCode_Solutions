class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> cur,prev;
        for(int i:arr){
            unordered_set<int> temp;
            for(int j:prev){
                temp.insert(i|j);
            }
            temp.insert(i);
            prev=temp;
            for(int j:prev)
                cur.insert(j);
        }
        
        return cur.size();
    }
};