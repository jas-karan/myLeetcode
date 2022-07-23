class Solution {
public:
    int find(string s,int i,int sign){
        long long ans=0;
        while(i<s.length()&& s[i]>='0'&&s[i]<='9'){
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX && sign==1){ ans=INT_MAX; break;}
            if(sign==-1 && ans*-1<INT_MIN){ ans=INT_MIN; break;}
            i++;
        }
        ans*=sign;
        return ans;
    }
    
    int myAtoi(string s) {
        int ans=0;
        int sign=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+'){
                ans=find(s,i+1,sign);
                break;
            }
            else if(s[i]=='-'){
                sign*=-1;
                ans=find(s,i+1,sign);
                break;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                ans=find(s,i,sign);
                break;
            }
            else if(s[i]==' ') continue;
            else break;
        }
        return ans;
    }
};