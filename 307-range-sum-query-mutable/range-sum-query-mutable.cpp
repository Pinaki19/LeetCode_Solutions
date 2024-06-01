class NumArray {
private:
int size;
vector<int> arr;
void build(int ind,int l,int r,auto& nums){
    if(l>r) return;
    if(l==r){
        arr[ind]=nums[l];
        return;
    }
    int mid=l+(r-l)/2;
    int left=2*ind+1;
    int right=2*ind+2;
    build(left,l,mid,nums);
    build(right,mid+1,r,nums);
    arr[ind]=arr[left]+ arr[right];
    
}

void update_ind(int ind,int l,int r,int i,int val){
    if(l>r||i<l || i>r) return;
    if(l==r){
        arr[ind]=val;
        return;
    }
    int mid=l+(r-l)/2;
    int left=2*ind+1;
    int right=2*ind+2;
    update_ind(left,l,mid,i,val);
    update_ind(right,mid+1,r,i,val);
    arr[ind]=arr[left]+arr[right];
}


int getSum(int ind,int l,int r,int left,int right){
    if(l>r) return 0;
    if(l>=left && r<=right) return arr[ind];
    else if(right<l || left>r || l==r) return 0;
    int mid=l+(r-l)/2;
    int left_child=2*ind+1;
    int right_child=2*ind+2;
    return getSum(left_child,l,mid,left,right)+getSum(right_child,mid+1,r,left,right);
}
public:
    NumArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        size=nums.size();
        arr.resize(4*size);
        build(0,0,size-1,nums);
    }
    
    void update(int index, int val) {
        update_ind(0,0,size-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return getSum(0,0,size-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */