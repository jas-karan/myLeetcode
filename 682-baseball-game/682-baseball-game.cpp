class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int>v;
        for(int i=0;i<op.size();i++){
            int sz = v.size();
            if(op[i]=="+"){
                v.push_back(v[sz-1]+v[sz-2]);
            }
            else if(op[i]=="D"){
                v.push_back(2*v[sz-1]);
            }
            else if(op[i]=="C") v.pop_back();
            else{
                v.push_back(stoi(op[i]));
            }
        }
        
        int res = 0;
        for(int i:v) res+=i;
        
        return res;
    }
};