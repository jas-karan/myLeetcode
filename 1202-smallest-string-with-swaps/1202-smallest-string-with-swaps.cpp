class Solution {
public:
   // ----------Form components-----------------
   // --indices in same component can be changed to each other---
   // so sort chars at indices of same component.
    
    vector<int> indices;       //Stores indices of same component.
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;       //Stores string formed by indices in the same component.
    
    void dfs(string &s,int n)         
    {
        visited[n]=true;
        indices.push_back(n);
        indiceString+=s[n];
        for(int &i:adjList[n])
            if(!visited[i])
               dfs(s,i);
        
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        adjList.resize(s.length());
        visited.resize(s.length(),false);
        
        for(vector<int> &v:pairs)               //Create graph using the indice pairs
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        
        for(int i=0;i<s.length();i++)
            if(!visited[i])
            {
                indiceString="";                              
                indices.clear();                             
                dfs(s,i);
                sort(indiceString.begin(),indiceString.end());  //Sort the chars in the same compo.
                sort(indices.begin(),indices.end());  //Sort the indices in the same compo.
                
                for(int i=0;i<indices.size();i++)    //replace indices with sorted chars
                    s[indices[i]]=indiceString[i];
            }
        return s;
    }
};