/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) return head;

        ListNode* before = new ListNode(0);
        before->next = head;

        ListNode* trav = before;
        int pos = 0;

        ListNode* breakPoint;
        ListNode* last;

        ListNode* connect = new ListNode(0);
        ListNode* reverseTrav = connect;

        while(trav != NULL) {
            if (pos == m - 1) {
                breakPoint = trav;
            } else if (pos >= m && pos <= n) {
                reverseTrav->val = trav->val;
                ListNode* nextConnect = new ListNode(0);
                nextConnect->next = reverseTrav;
                if (pos == m) last = reverseTrav;
                if (pos == n) {
                    breakPoint->next = reverseTrav;
                    last->next = trav->next;
                    break;
                }
                reverseTrav = nextConnect;
            }
            trav = trav->next;
            pos++;
        }

        return before->next; 
    }
};
// @lc code=end

