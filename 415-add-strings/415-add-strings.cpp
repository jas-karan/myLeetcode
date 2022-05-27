class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        
        int i=num1.length()-1,j=num2.length()-1;
        
        int carry=0;
        
        while(i>=0 || j>=0 || carry){
            int curr = 0;
            if(i>=0){
                curr+=num1[i]-'0';
                i--;
            }
            if(j>=0){
                curr+=num2[j]-'0';
                j--;
            }
            if(carry){
                curr+=carry;
            }
            
            ans = (char)(curr%10+'0')+ans;
            carry = curr/10;
        }
        
        return ans;
    }
};