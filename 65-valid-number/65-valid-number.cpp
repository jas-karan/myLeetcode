class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i = 0, digits = 0, dots = 0;
        
        for (; i < n && isspace(s[i]); i++); //skip whitespaces
        
        if (s[i] == '+' || s[i] == '-') {  //skip sign if there
            i++;
        }
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++) {
            isdigit(s[i]) ? digits++ : dots++;
        }
        if (digits<1 || dots > 1) {   //// no more than one point and at least one digit
            return false;
        }
        //significand part done, now exponent part->
        
        
        //if there is exponent part-
        if (s[i] == 'e' || s[i] == 'E') {
            i++;
            if (s[i] == '+' || s[i] == '-') {  //skip the sign
                i++;
            }
            digits = 0;
            for (; i < n && isdigit(s[i]); i++) {
                digits++;
            }
            if (!digits) {   //should be atlease one digit after e
                return false;
            }
        }
        for (; i < n && isspace(s[i]); i++);  //skip trailing whitespaces
        return i == n;  //all characters should be checked 
    }
};