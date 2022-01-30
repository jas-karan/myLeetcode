class Solution {
public:
    static bool myCmp(string a,string b){
        return (a+b)>(b+a);
    }
    
    string largestNumber(vector<int>& nums) {
        string s = "";
        vector<string> str;
        for(int x:nums){
            str.push_back(to_string(x));
        }
        sort(str.begin(),str.end(),myCmp);
        if(str[0]=="0") return "0";
        for(string x:str){
            s += x;
        }
        return s;
    }
};