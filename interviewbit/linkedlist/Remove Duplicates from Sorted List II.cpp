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

	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *prev = dummy, *curr = head;
	while(curr != NULL){
		while(curr->next != NULL && (curr->val == curr->next->val))
			curr = curr->next;
		if(prev->next == curr)
			prev = prev->next;
		else
			prev->next = curr->next;
		curr = curr->next;
	}
	return dummy->next;
}