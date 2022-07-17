class Solution {
public:
    char slowestKey(vector<int>& t, string keys) {
        int n=t.size();
        
        int prev=0;
        int ans=-1;
        char c;
        
        for(int i=0;i<n;i++){
            int d = t[i]-prev;
            if(d>ans){
               ans=d;c=keys[i];
            }
            else if(d==ans){
                c= keys[i]>c?keys[i]:c;
            }
            prev=t[i];
        }
        
        return c;
    }
};