/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void reverse(ListNode **second) {
	ListNode *prev = NULL, *curr = *second, *next;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*second = prev;
}

ListNode* Solution::reorderList(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(head == NULL || head->next == NULL)
		return head;
	int n = 0;
	ListNode *curr = head;
	while(curr != NULL){
		curr = curr->next;
		n += 1;
	}
	n = n - 1;
	int sec = n/2;
	ListNode *second = NULL;

	// get the second half of list from n-n/2 to n
	curr = head;
	for(int i=0;i<=sec;i++){
		curr = curr->next;
	}
	second = curr;
	reverse(&second);

	curr = head;
	ListNode *temp;
	while(curr != NULL && second != NULL){
		temp = curr->next;
		curr->next = second;
		second = second->next;
		curr->next->next = temp;
		curr = temp;
	}
	if(curr != NULL)
		curr->next = NULL;
	return head;
}