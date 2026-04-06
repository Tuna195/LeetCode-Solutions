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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = nullptr; int a = 0; ListNode* part1 = nullptr;
        ListNode* greater = nullptr; int b = 0; ListNode* part2 = nullptr;
        while(head != nullptr){
            if(head->val >= x){
                if(b == 0){
                    greater = head;
                    part2 = head;
                    b = 1;
                }
                else{
                    greater->next = head;
                    greater = head;
                }
            }
            else{
                if(a == 0){
                    smaller = head;
                    part1 = head;
                    a = 1;
                }
                else{
                    smaller->next = head;
                    smaller = head;
                }
            }
            head = head->next;
        }
        if(greater != nullptr) greater->next = nullptr;
        if(part1 != nullptr){
            smaller->next = part2;
            return part1;
        }
        else return part2;
    }
};