/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(head == NULL || head->next == NULL)
		return head;
	ListNode *curr = head, *next;
	while(curr->next != NULL){
		next = curr->next;
		if(curr->val == next->val){
			curr->next = next->next;
			free(next);
		}else{
			curr = curr->next;
		}
	}
	return head;
}