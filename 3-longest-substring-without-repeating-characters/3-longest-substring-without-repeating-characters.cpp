class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //keep a window,
        //once window has an element with freq>1
        //shrink the window and update the length
        
        unordered_map<int,int>window;
        int length=0;
        
        int l=0,r=0;
        
        while(r<s.length()){
            window[s[r]]++;
            
            while(l<r && window[s[r]]>1){
                window[s[l]]--;
                l++;
            }
            r++;
            length = max(length,r-l);
        }
        
        return length;
    }
};