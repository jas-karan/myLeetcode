class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int i=0;
        int ans=INT_MAX;
        unordered_map<int,int>map;
        while(i<n){
            if(map.find(cards[i])!=map.end()){
                ans=min(ans,i-map[cards[i]]+1);
            }
            map[cards[i]]=i;
            i++;
        }
        return ans==INT_MAX ? -1:ans;
    }
};