/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(head == NULL || head->next == NULL)
		return head;

	ListNode *prev = head, *curr = head->next, *next;
	head = curr;
	while(1){
		next = curr->next;
		curr->next = prev;
		if(next == NULL || next->next == NULL){
			prev->next = next;
			break;
		}
		prev->next = next->next;
		prev = next;
		curr = prev->next;
	}
	return head;
}