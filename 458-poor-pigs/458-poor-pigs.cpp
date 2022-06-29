class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //one pig can test atmost (minutesToTest/minutesToDie)+1;
        
        int pig=0;
        int each=(minutesToTest/minutesToDie)+1;
        while(pow(each,pig)<buckets) pig++;
        return pig;
    }
};