/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto l:lists) if(l) pq.push({l->val,l});
        
        ListNode*dummy= new ListNode();
        ListNode*prev= dummy;
        
        while(!pq.empty()){
            auto node = pq.top().second;
            pq.pop();
            prev->next=node;
            prev=node;
            if(node->next) pq.push({node->next->val,node->next});
        }
        
        return dummy->next;
    }
};