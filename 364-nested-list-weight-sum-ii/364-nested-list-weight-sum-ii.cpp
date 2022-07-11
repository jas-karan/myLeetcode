/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger>q;
        for(NestedInteger i:nestedList){
            q.push(i);
        }
        
        int maxd= 0;
        int sumEl=0;
        int sumPr=0;
        int depth=1;
        
        while(!q.empty()){
            int sz = q.size();
            maxd = max(maxd,depth);
            while(sz--){
                NestedInteger i = q.front();
                q.pop();
                if(i.isInteger()){
                    sumEl += i.getInteger();
                    sumPr += i.getInteger()*depth;
                }
                else{
                    for(NestedInteger j:i.getList()){
                        q.push(j);
                    }
                }
            }
            depth++;
        }
        
        return (maxd+1)*sumEl - sumPr;
        
    }
};