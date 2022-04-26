class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& A) {
        int n = A.size();
        
        vector<int> res(n);
        stack<int>st;
        
        for (int i = 0; i < n; ++i) {
            
            //shorter elements can see this element
            while (!st.empty() && A[st.top()] <= A[i])
                res[st.top()]++, st.pop();
            
            //if there is a longer element, it can view current element (first longer than him)
            //(in stack, elements will be in decreasing order)
            if (!st.empty())
                res[st.top()]++;
            st.push(i);
        }
        return res;
        
        
    }
};