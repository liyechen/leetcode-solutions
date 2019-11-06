/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0);
        ans.next = head;

        ListNode* lastNode = &ans;

        ListNode* trav = head;
        while(trav != NULL) {
            if (trav->next != NULL && trav->next->val != trav->val) {
                lastNode = trav;
                trav = trav->next;
                continue;
            }
            // erase duplicate numbers
            if (trav->next != NULL && trav->next->val == trav->val) {
                int val = trav->val;
                while(trav->val == val) {
                    trav = trav->next;
                    if (trav == NULL) break;
                }
                lastNode->next = trav;
                continue;
            }
            trav = trav->next;
        }
        return ans.next;
    }
};
// @lc code=end

