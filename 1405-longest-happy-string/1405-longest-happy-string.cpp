class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        char p1='$',p2='$';
        while(pq.size()){
            auto f = pq.top(); pq.pop();
            if(f.second==p1&&f.second==p2){
                if(pq.size()==0) return ans;
                auto s = pq.top(); pq.pop();
                ans+=s.second;
                pq.push(f);
                if((s.first)>1) pq.push({s.first-1,s.second});
                p1=p2;
                p2=s.second;
            }
            else{
                ans+=f.second;
                if(f.first>1) pq.push({f.first-1,f.second});
                p1=p2;
                p2=f.second;
            }
        }
        
        return ans;
    }
};