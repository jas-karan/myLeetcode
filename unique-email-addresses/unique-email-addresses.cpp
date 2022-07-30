class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>set;
        
        for(string e:emails){
            string s = "";
            int i;
            bool plus = false;
            for(i=0;i<e.length();i++){
                if(e[i]=='@') break;
                if(e[i]=='+'){
                    plus=true;
                }
                if(plus) continue;
                if(e[i]!='.') s+=e[i];
            }
            s+=e.substr(i);
            set.insert(s);
        }
        
        return set.size();
    }
};