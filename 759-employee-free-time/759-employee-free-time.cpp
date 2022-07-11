/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval>ans;
        map<int,int>map;
        
        for(auto e:schedule){
            for(auto i:e){
                map[i.start]=max(map[i.start],i.end);
            }
        }
        
        int pre = INT_MIN;
        
        for(auto [s,e]:map){
            if(pre<s){
                if(pre!=INT_MIN)
                    ans.push_back(Interval(pre,s));
            }
            pre = max(pre,e);
        }
        
        return ans;
    }
};