class Solution {
public:
//     vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
//         int n = words.size(),q = queries.size();
//         for(string&s:queries) sort(s.begin(),s.end());
//         for(string&s:words) sort(s.begin(),s.end());
        
//         vector<int>ans;
        
//         for(string q:queries){
//             int f1=0;
//             for(char c:q){
//                 if(c==q[0]) f1++;
//                 else break;
//             }
//             int res = 0;
//             for(string w:words){
//                 int f2 = 0;
//                 for(char c:w){
//                     if(c==w[0]) f2++;
//                     else break;
//                 }
                
//                 if(f1<f2)res++;
//             }
            
//             ans.push_back(res);
//         }
        
//         return ans;
//     }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fr(12, 0); //count of strings with frequency i
        int f;
        vector<int> q;
        for(int i = 0; i < words.size(); i++){
            f = getF(words[i]);
            fr[f]++;
        }
		//Find cumulative frequency i.e. ith item will have sum of i..end.
        for(int i = 9; i >= 0; i--){
            fr[i] = fr[i] + fr[i+1];
        }
        
        for(int i = 0; i < queries.size(); i++){
            f = getF(queries[i]);
            q.push_back(fr[f+1]);  //count of words with frequency fr+1 or greater
        }
        return q;
    }
    /*Helper function to calculate frequency of smallest element*/
    int getF(string &s){
        int a[26] = {0,};
        for(int i = 0; i < s.size(); i++){
            a[s[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(a[i] != 0) return a[i];
        }
        return 0;
    }
};