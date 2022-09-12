class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>valid;
        
        for(string e:emails){
            
            int i=0;
            string newEmail = "";
            
            for(int i=0;i<e.length();i++){
                char c= e[i];
                if(c=='+' ||c=='@') break;
                if(c=='.') continue;   
                newEmail+=c;
            }
            
            while(e[i]!='@') i++;
            
            while(i<e.length()){
                newEmail+=e[i];
                i++;
            }
            
            valid.insert(newEmail);
        }
        
        return valid.size();
    }
};