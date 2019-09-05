/*
 * Created by liyechen
 * Time 2019/09/05 14:22
 * Email <gliyechen@hotmail.com>
 */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int size = getListNodeSize(head);
        k = k % size;
        k = size - k;
        if (k == 0) return head;
        ListNode* breakNode = head;
        while(k > 1) {
            breakNode = breakNode->next;
            k--;
        }
        ListNode* ans = breakNode->next;
        breakNode->next = NULL;
        return ans;
    }

private:
    int getListNodeSize(ListNode* head) {
        ListNode* recordHead = head;
        int count = 0;
        while(true) {
            count++;
            if (head->next == NULL) {
                head->next = recordHead;
                break;
            } else {
                head = head->next;
            }
        }
        return count;
    }
};
