class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        unordered_map<int,vector<int>>from;
	    vector<int>indeg(n,0);
	
	    int done = 0;
	
	    for(vector<int> p:prereq){
		    indeg[p[0]]++;
            from[p[1]].push_back(p[0]);  //y->x
		    //so that if y is poped then all x st y->x can decrease indegrees
	    }
	
	    queue<int>q;
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
	
	    while(!q.empty()){
		    int curr = q.front(); q.pop();
		    for(int to:from[curr]){
			    indeg[to]--;
			    if(indeg[to]==0) q.push(to);
            }
		    done++;
	    }
	
	    if(done==n) return 1;
	    else return 0;
    }
};