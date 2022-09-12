class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        int l=0,r=n-1,boats=0;
        while(l<=r){
            if(l==r){
                boats++;
                break;
            }
            if(people[l]+people[r]>limit){
                boats++;
                r--;
            }
            else{
                boats++;
                l++;
                r--;
            }
        }
        
        return boats;
    }
};