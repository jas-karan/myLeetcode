class Solution {
public:
//     int dominoRotations(vector<int>& tops, vector<int>& bottoms)
//     {
//         int minRotation = INT_MAX;
//         for(int i = 1; i <= 6; ++i)
//         {
//             int swap = 0 , j;
//             for(j = 0; j<tops.size(); ++j)
//                 {
//                     if(tops[j] == i)
//                         continue;
//                     else if(bottoms[j] == i)
//                         ++swap;
//                     else
//                         break;
//                 }
                
//                 // if we reach at the end of vector && minRotation > swap
//                 if(j == tops.size() && minRotation > swap)
//                     minRotation = swap;
//         }
//         return minRotation == INT_MAX ? -1 : minRotation;
//     }
    
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        
//         // try to make all tops faces same
//         int ab = dominoRotations(tops,bottoms);
        
//         // try to make all bottoms faces same
//         int ba = dominoRotations(bottoms,tops);
        
//         return ab == -1 ? ba : ba == -1 ? ab : min(ab,ba);
        int n = top.size();
        
        vector<int>t(7,0),b(7,0),s(7,0);
        
        for(int i=1;i<=6;i++){
            for(int j=0;j<n;j++){
                if(top[j]==i) t[i]++;
                if(bottom[j]==i) b[i]++;
                if(top[j]==i && bottom[j]==i) s[i]++;
            }
        }
        
        for(int i=1;i<=6;i++){
            if(t[i]+b[i]-s[i]==n) return min(t[i],b[i])-s[i];
        }
        
        return -1;
    }
};