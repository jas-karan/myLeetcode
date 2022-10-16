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
        int n = lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        
        ListNode*head = new ListNode(0);
        ListNode*prev = head;
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        
        for(auto l:lists){
            if(l) pq.push({l->val,l});
        }
        
        while(pq.size()){
            auto [val,ptr] = pq.top();
            pq.pop();
            
            prev->next = ptr;
            prev = ptr;
            
            if(ptr->next) pq.push({ptr->next->val,ptr->next});
        }
        
        return head->next;
    }
};