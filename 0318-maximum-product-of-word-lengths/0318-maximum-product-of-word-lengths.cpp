class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>bit(n);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int mask=0;
            for(char c:words[i]){
                mask|=(1<<(c-'a'));
            }
            bit[i]=mask;
            for(int j=0;j<i;j++){
                if((bit[j]&bit[i])==0){
                    ans = max(ans, (int)words[i].length()*(int)words[j].length());
                }
            }
        }
        
        return ans;
    }
};