class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>s,e;
        int n=intervals.size();
        for(auto i:intervals){
            s.push_back(i[0]);
            e.push_back(i[1]);
        }
        sort(begin(s),end(s));
        sort(begin(e),end(e));
        
        int room=0;
        int ans=0;
        int i=0,j=0;
        while(i<n&&j<n){
            if(s[i]<e[j]){
                room++;
                i++;
            }
            else{
                room--;
                j++;
            }
            ans=max(ans,room);
        }
        
        return ans;
    }
};