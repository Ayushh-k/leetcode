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

    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        curr->next = left ? left : right;

        return dummy.next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* middle = getMiddle(head);

        ListNode* rightHead = middle->next;
        middle->next = nullptr;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(rightHead);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};