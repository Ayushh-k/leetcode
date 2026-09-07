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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        curr->next = (list1)?list1:list2;
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(!head||!head->next) return head;

        ListNode* mid = getMiddle(head);
        ListNode* nextToMiddle = mid->next;
        mid->next = nullptr;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(nextToMiddle);

        return merge(left,right);
        
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};