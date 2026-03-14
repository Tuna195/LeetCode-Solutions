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
    TreeNode* Build_HB_BST(vector<int> v, int left, int right){
        if(left > right) return nullptr;
        int mid = (left + right)/2;
        TreeNode *node = new TreeNode(v[mid]);
        node->left = Build_HB_BST(v, left, mid-1);
        node->right = Build_HB_BST(v, mid + 1, right);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        return Build_HB_BST(v, 0, n-1);

    }
};