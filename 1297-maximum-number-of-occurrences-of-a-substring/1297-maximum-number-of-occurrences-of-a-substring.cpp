class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int result=0;
        unordered_map<int,int> count;           	//Stores count of letters in the window.
        unordered_map<string,int> occurence;        //Stores count of occurence of that string.
        for(int i=0;i<s.length();i++)			//Sliding window
        {
            count[s[i]]++;						//Increase the count of letter at i.
            if(i>=minSize)                  //Reduce the size of the window if increased to size.
            {
                if(--count[s[i-minSize]]==0)			//Remove the letter from map if count 0 to track unique letters.
                    count.erase(s[i-minSize]);
            }
            if(i>=minSize-1&&count.size()<=maxLetters)	//When the substring in the window matches the constraints.
                result=max(result,++occurence[s.substr(i-minSize+1,minSize)]); //Increase the occurence count of the string and get the max.
        }
        return result;
        
    }
};