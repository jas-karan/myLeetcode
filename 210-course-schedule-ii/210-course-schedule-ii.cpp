class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        
        vector<vector<int>>graph(numCourses);
        vector<int>count(numCourses,0);
        
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]);
            count[p[0]]++;
        }
        
        
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(count[i]==0){
                q.push(i);
            }
        }
        
        while(q.size()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(int c:graph[course]){
                count[c]--;
                if(count[c]==0){
                    q.push(c);
                }
            } 
        }
        
        return ans.size()==numCourses ? ans: vector<int>();
        
    }
};