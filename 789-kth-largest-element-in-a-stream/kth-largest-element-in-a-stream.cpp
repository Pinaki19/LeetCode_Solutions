class KthLargest {
private:
    int k;
public:
    function<bool(int,int)> comp=[](int x,int y){
        if(x==y) return false;
        return x>y;
    };
    multiset<int,decltype(comp)> s;
    KthLargest(int k, vector<int>& nums):s(comp) {
        this->k=k;
        for(int i:nums)
            s.insert(i);
    }
    
    int add(int val) {
        s.insert(val);
        return *(next(s.begin(),k-1));
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */