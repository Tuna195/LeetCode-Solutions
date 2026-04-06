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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        int cnt = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            cnt++;
        }
        tail = head;
        for(int i = 1; i < cnt - n; i++){
            tail = tail->next;
        }
        if(head->next == nullptr && n == 1) return nullptr;
        if(n == cnt) return head->next;
        if(tail->next != nullptr)
            tail->next = (tail->next)->next;
            
        return head;
    }
};