class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //keep a window,
        //once window has an element with freq>1
        //shrink the window and update the length
        
//         unordered_map<int,int>window;
//         int length=0;
        
//         int l=0,r=0;
        
//         while(r<s.length()){
//             window[s[r]]++;
            
//             while(l<r && window[s[r]]>1){
//                 window[s[l]]--;
//                 l++;
//             }
//             r++;
//             length = max(length,r-l);
//         }
        
//         return length;
        
        unordered_map<char,int>mp;
        int length=0;
        
        int l=0;
        
        for(int r=0;r<s.length();r++){
            if(mp.find(s[r]) != mp.end()){
                l = max(l,mp[s[r]]+1);
            }
            length = max(length,r-l+1);
            mp[s[r]]=r;
        }
        
        return length;
    }
};