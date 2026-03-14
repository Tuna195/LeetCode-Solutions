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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Build_HB_BST(ListNode* &currentNode, int n){
        if(n == 0) return nullptr;
        int left = n/2;
        TreeNode* leftNode = Build_HB_BST(currentNode, left);
        TreeNode* newNode = new TreeNode(currentNode->val);
        newNode->left = leftNode;
        currentNode = currentNode->next;
        TreeNode* rightNode = Build_HB_BST(currentNode, n - left - 1);
        newNode->right = rightNode;
        return newNode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
    
        int n = 0;
        ListNode* currentNode = head;
        while(head != nullptr){
            head = head->next;
            n++;
        }
        return Build_HB_BST(currentNode, n);

    }
};