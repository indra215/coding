/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* head, int x) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(head == NULL || head->next == NULL)
    	return head;

	ListNode *greater = NULL, *curr = head, *prev = NULL, *last;
	while(curr != NULL){
		if(curr->val >= x){
			if(prev == NULL){
				head = curr->next;
			}else{
				prev->next = curr->next;
			}
			if(greater == NULL){
				greater = curr;
				last = greater;
			}else{
				last->next = curr;
				last = last->next;
			}
		}else{
			prev = curr;
		}
		curr = curr->next;
	}
	if(greater == NULL)
		return head;

	if(prev != NULL)
		prev->next = NULL;
	last->next = NULL;

	curr = greater;
	ListNode *pre = NULL;
	while(curr != NULL){
		if(curr->val == x){
			if(pre == NULL){
				greater = curr->next;
			}else{
				pre->next = curr->next;
			}
			prev->next = curr;
			curr->next = greater;
			break;
		}else{
			pre = curr;
			curr = curr->next;
		}
	}
	if(curr == NULL){
		prev->next = greater;
	}
	return head;
}