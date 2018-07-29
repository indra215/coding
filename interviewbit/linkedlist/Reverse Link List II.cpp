/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(head == NULL)
		return head;
	ListNode *prev = NULL, *curr = head, *next;
	for(int i=1;i<m;i++){
		prev = curr;
		curr = curr->next;
	}
	ListNode *first = prev, *second = curr;
	prev = NULL;
	while(m <= n){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		m++;
	}
	second->next = curr;
	if(first == NULL)
		return prev;

	if(first != NULL)
		first->next = prev;

	return head;
}