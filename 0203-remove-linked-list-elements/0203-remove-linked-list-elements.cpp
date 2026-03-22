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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val){
            head = head->next;
        }
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* next_node = head->next; 
        while(next_node != nullptr && next_node->val == val){
            head->next = next_node->next;
            next_node = head->next;
        }
        if(next_node == nullptr) return head;

        ListNode* next_next_node = next_node->next;

        while(next_next_node != nullptr){
            if(next_next_node->val == val){
                next_node->next = next_next_node->next;
            }
            else{
                next_node = next_next_node;
            }
            next_next_node = next_next_node->next;
        }
        return head;
    }
};