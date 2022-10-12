class Solution {
public:
    int perf(char ch,int a,int b){
        int val;
        switch(ch){
            case '*':
               val=a*b;
               break;
            case '+':
                val=a+b;
                break;
            case '-':
                val=a-b;
                break;
        }
        return val;
    }
    
    
    vector<int> diffWaysToCompute(string e) {
        vector<int>res;
        for(int i=0;i<e.length();i++){
            if(!isdigit(e[i])){
                vector<int>va = diffWaysToCompute(e.substr(0,i));
                vector<int>vb = diffWaysToCompute(e.substr(i+1));
                
                for(int a:va){
                    for(int b:vb){
                        res.push_back(perf(e[i],a,b));
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(e));
        return res;
    }
};