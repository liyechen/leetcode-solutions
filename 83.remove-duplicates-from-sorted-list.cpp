/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
        if (head == NULL) return head;

        ListNode ans(0);
        ans.next = head;

        ListNode* trav = head;
        while(trav != NULL) {
            if (trav->next) {
                if (trav->next->val != trav->val) {
                    trav = trav->next;
                    continue;
                }
                if (trav->next->val == trav->val) {
                    while(trav->next->val == trav->val) {
                        trav->next = trav->next->next;
                        if (trav->next == NULL) {
                            break;
                        }
                    }
                    trav = trav->next;
                    continue;
                }
            }
            trav = trav->next;
        }
        return ans.next;
    }
};
// @lc code=end

