class Solution {
public:
    int numRabbits(vector<int>& answers) {
        //we have to form groups of rabits of same color
        //consider [1,1,2,1] 
        //first rabit is saying there is 1 more rabit of his color(c1) means total group
        //size 2 (of which one has been found)
        //i=0 : c1 - 2(1) 
        //i=1 : c1 - 2(2)  2nd says there are 2 in his group ,group of size 2 is already
        //there and 1 seat is vacant 
        //i=2 : c1 - 2(2) , c2 - 3(1) 
        //i=3 : c1 - 2(2) , c2 - 3(1) , c3 - 2(1)
        //since group of 2 is full, we create another group of 2
        //total 2+3+2 = 7 rabits are there among which 3 rabits have interviewed
        
//         unordered_map<int,vector<int>>group;
        
//         for(int a:answers){
//             if(group.find(a+1)==group.end()){
//                 group[a+1].push_back(1);  //make the group
//             }
//             else{
//                 int sz = group[a+1].size();
//                 if(group[a+1][sz-1]==a+1){
//                     group[a+1].push_back(1); //create one more group of similar size
//                 }
//                 else group[a+1][sz-1]++; //fill the seat
//             }
//         }
        
//         int rabbits=0;
        
//         for(auto g:group){
//             rabbits+=(g.first*g.second.size());
//         }
        
//         return rabbits;
        
        //optimise memory
        
        unordered_map<int,int>group;
        int rabbits= 0;
        for(int a:answers){
            if(group.find(a+1)==group.end()) group[a+1]=1;
            else{
                if(group[a+1]==a+1){
                    rabbits+=a+1;  //store the group and reinitialise
                    group[a+1]=1;
                }
                else group[a+1]++;
            }
        }
        
        for(auto g:group){
            rabbits+=g.first;
        }
        
        return rabbits;
    }
};