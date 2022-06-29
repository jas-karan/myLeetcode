class Solution {
public:
    string orderlyQueue(string s, int k) {
        //if we can swap adjacent characters of string , we can sort it (as in bubble sort)
        //in this ques, swapping can be achieved for k>1
        //thus, for k>1 we simply sort and for k=1, we return smallest permutation
        
        if(k==1){
            string ans = s;
            for(int i=0;i<s.length();i++){
                s = s.substr(1)+s[0];
                if(s<ans) ans=s;
            }
            return ans;
        }
        
        sort(s.begin(), s.end());
        return s;
    }
};