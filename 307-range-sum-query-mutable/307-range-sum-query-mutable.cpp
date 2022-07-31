class NumArray {
public:
    int lsb(int n){
        return n&-n;
    }
    
    int sz;
    vector<int>BIT,nums;
    
    void updateBIT(int ind,int val){
        for(int i=ind;i<sz;i+=lsb(i)) BIT[i]+=val;
    }
    
    int sumBIT(int ind){
        int s=0;
        for(int i=ind;i>0;i-=lsb(i)) s+=BIT[i];
        return s;
    }
    
    NumArray(vector<int>& nums) {
        sz = nums.size()+1;
        BIT = vector<int>(sz,0);
        this->nums = nums;
        for(int i=1;i<sz;i++){
            updateBIT(i,nums[i-1]);
        }
    }
    
    void update(int index, int val) {
        int old = nums[index];
        nums[index]=val;
        updateBIT(index+1,val-old);
    }
    
    int sumRange(int left, int right) {
        left++;right++;
        return sumBIT(right)-sumBIT(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */