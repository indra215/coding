/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(head == NULL)
		return head;
	int total = 0;
	ListNode *curr = head;
	while(curr != NULL){
		total += 1;
		curr = curr->next;
	}
	if(n >= total){
		ListNode *temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	total = total - n;
	curr = head;
	for(int i=0;i<total-1;i++){
		curr = curr->next;
	}
	ListNode *temp = curr->next;
	curr->next = temp->next;
	free(temp);
	return head;
}