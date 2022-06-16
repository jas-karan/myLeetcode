class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        
        sort(A.begin(), A.end());
        
        string res = "";
        
        do {
            string hours = {(char)(A[0] + '0'), (char)(A[1] + '0')};
            string minutes = {(char)(A[2] + '0'), (char)(A[3] + '0')};
            
            res = (stoi(hours) <= 23 && stoi(minutes) <= 59) ? (hours + ":" + minutes) : res;
            
        } while(next_permutation(A.begin(), A.end()));
        
        return res;
    }
};