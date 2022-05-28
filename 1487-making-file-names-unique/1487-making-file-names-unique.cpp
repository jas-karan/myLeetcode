class Solution {
public:
    unordered_map<string,int>map;
    
    vector<string> getFolderNames(vector<string>& names) {
        vector<string>res;
        
        for(string s:names){
            if(map.find(s)==map.end()){
                res.push_back(s);
                map[s]=1;  //occurred once
            }
            else{
                int k=map[s];
                while(map.find(s+"("+to_string(k)+")")!=map.end()){k++; map[s]++;}
                res.push_back(s+"("+to_string(k)+")");
                map[s]++;
                map[s+"("+to_string(k)+")"]=1;
            }
        }
        
        return res;
    }
};