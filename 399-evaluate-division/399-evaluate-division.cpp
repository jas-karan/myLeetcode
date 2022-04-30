class Solution {
    
    double evaluate(unordered_map<string, vector<pair<string, double>>> &graph, vector<string> &query) {
        auto startNode = query[0];
        auto endNode = query[1];
        
        if (graph.find(startNode) == graph.end()) {
            return -1;
        }
        
        if (graph.find(endNode) == graph.end()) {
            return -1;
        }
        
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        
        q.push({startNode, 1});
        visited.insert(startNode);
        
        while (!q.empty()) {
            auto frontItem = q.front();
            q.pop();
            
            auto currNode = frontItem.first;
            auto currValue = frontItem.second;
            
            if (currNode == endNode) {
                return currValue;
            }
            
            for (auto nbr: graph[currNode]) {
                auto node = nbr.first;
                auto weight = nbr.second;
                if (visited.find(node)==visited.end()) {
                    visited.insert(node);
                    q.push({node, currValue * weight});
                }
            }
        }
        
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            auto fromNode = equations[i][0];
            auto toNode = equations[i][1];
            double weight = values[i];
            
            graph[fromNode].push_back({toNode, weight});
            graph[toNode].push_back({fromNode, 1 / weight});
        }
        
        vector<double> answers;
        
        for (auto query: queries) {
            answers.push_back(evaluate(graph, query));
        }
        
        return answers;
    }
};