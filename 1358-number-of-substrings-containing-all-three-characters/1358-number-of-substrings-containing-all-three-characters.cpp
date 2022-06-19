class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int res=0;
//         for(int i=0;i<n-2;i++){
//             bool a=false,b=false,c=false;
            
//             for(int j=i;j<n;j++){
//                 if(s[j]=='a') a=true;
//                 else if(s[j]=='b') b=true;
//                 else c=true;
                
//                 if(a && b && c){
//                     res+= (n-j);
//                     break;
//                 }
//             }
//         }
        
//         vector<int>a(n,n),b(n,n),c(n,n);
//         int ai = n,bi = n,ci = n;
//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='a') ai=i;
//             else if(s[i]=='b') bi=i;
//             else ci=i;
            
//             a[i]=ai; b[i]=bi; c[i]=ci;
//         }
        
        
//         for(int i=0;i<n;i++){
//             res+=n-max({a[i],b[i],c[i]});
//         }
//         return res;
        
        map<char, int> f;
        int l=0, r=0;
        
        while(r < n) {
            f[s[r]]++;
            while(f['a'] && f['b'] && f['c']) {
                res += n-r;
                f[s[l++]]--;
            }
            r++;
        }
        return res;
    }
};