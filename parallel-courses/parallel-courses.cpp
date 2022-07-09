class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int>indeg(n+1,0);
        vector<vector<int>>gr(n+1);
        for(auto r:relations){
            indeg[r[1]]++;
            gr[r[0]].push_back(r[1]);
        }
        
        queue<int>q;
        for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);
        
        int sem=0;
        int courses=0;
        while(!q.empty()){
            sem++;
            int sz=q.size();
            
            while(sz--){
                int cur=q.front(); q.pop();
                courses++;
                
                for(int nbr:gr[cur]){
                    indeg[nbr]--;
                    if(indeg[nbr]==0) q.push(nbr);
                }
            }
        }
        
        return courses==n?sem:-1;
    }
};