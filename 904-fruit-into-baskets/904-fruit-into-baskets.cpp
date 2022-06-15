class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int res = 0;
        unordered_map<int,int>map;
        for(int r=0;r<fruits.size();r++){
            map[fruits[r]]++;
            
            while(map.size()>2){
                map[fruits[l]]--;
                if(map[fruits[l]]==0) map.erase(fruits[l]);
                l++;
            }
            
            res = max(res,r-l+1);
        }
        
        return res;
    }
};