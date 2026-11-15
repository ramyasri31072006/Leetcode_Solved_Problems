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
    ListNode* reverse(ListNode* node){

        if(node->next == NULL) return node;
        
        ListNode* prev = NULL;
        ListNode* cur = node;
        ListNode* front = NULL;

        while(cur != NULL){
            front = cur->next;
            cur->next = prev;
            prev = cur;
            cur = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;
        prev->next = reverse(mid);

        mid = prev->next;
        ListNode* temp = head;
        while(temp != prev->next ){
            if(temp->val != mid->val) return false;
            temp = temp->next;
            mid = mid->next;
        }
        return true;
    }
};