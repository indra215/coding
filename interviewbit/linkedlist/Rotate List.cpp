/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(head == NULL || head->next == NULL)
		return head;
	int total = 0;
	ListNode *curr = head;
	while(curr != NULL){
		total += 1;
		curr = curr->next;
	}
	ListNode *rotate;
	curr = head;
	k = k%total;
	if(k == 0)
		return head;
	total = total - k - 1;
	for(int i=0;i<total;i++){
		curr = curr->next;
	}
	rotate = curr->next;
	curr->next = NULL;
	curr = rotate;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = head;
	head = rotate;
	return head;
}