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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        ListNode* first = list1;
        ListNode* second = list2;

        while(first && second) {
            if(first->val < second->val) {
                ans->next = first;
                first = first->next;
            } else {
                ans->next = second;
                second = second->next;
            }
            ans = ans->next;
        }

        while(first) {
            ans->next = first;
            ans = ans->next;
            first = first->next;
        }
        while(second) {
            ans->next = second;
            ans = ans->next;
            second = second->next;
        }
        return head->next;
    }
};