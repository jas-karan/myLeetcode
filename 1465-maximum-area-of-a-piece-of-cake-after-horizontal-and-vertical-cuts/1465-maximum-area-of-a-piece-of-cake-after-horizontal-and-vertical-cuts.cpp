class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        sort(begin(hor),end(hor));
        sort(begin(ver),end(ver));
        
        long maxHeight = INT_MIN;
        long maxWidth = INT_MIN;
        
        for(int i=1;i<hor.size();i++) maxHeight=max(maxHeight,long(hor[i]-hor[i-1]));
        for(int i=1;i<ver.size();i++) maxWidth= max(maxWidth, long(ver[i]-ver[i-1]));
        
        //consider edges
        
        maxHeight= max({maxHeight,long(hor[0]),long(h-hor[hor.size()-1])});
        maxWidth = max({maxWidth, long(ver[0]),long(w-ver[ver.size()-1])});
        
        return (int)((maxWidth*maxHeight)%1000000007);
    }
};