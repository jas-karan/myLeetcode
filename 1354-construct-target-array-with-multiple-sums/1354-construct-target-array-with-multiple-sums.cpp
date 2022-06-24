class Solution {
public:
    bool isPossible(vector<int>& A) {
        long total = 0;
        int n = A.size();
        priority_queue<int> pq(A.begin(), A.end());
        for (int a : A)
            total += a;
        
        while (true) {
            long new_ = pq.top(); pq.pop();
            long rest = total-new_;
            
            //rest+old=new  => rest<new
            
            if (new_ == 1 || rest == 1)
                return true;
            
            if (new_ < rest || rest == 0 || new_ % rest == 0)
                return false;
            
            
            long old_ = new_ % rest;
            
            total-=new_;
            total+=old_;
            pq.push(old_);
        }
        
        return true;
    }
};