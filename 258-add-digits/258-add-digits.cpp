class Solution {
public:
    int addDigits(int num) {
        int curr = num;
        while(true){
            int sum = 0;
            while(curr){
                sum=sum+(curr%10);
                curr/=10;
            }
            curr=sum;
            if(curr/10==0) break;
        }
        return curr;
    }
};