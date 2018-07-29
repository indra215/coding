/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverse(ListNode **second){
	ListNode *prev, *curr, *next;
	prev = NULL;
	curr = *second;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*second = prev;
}

int Solution::lPalin(ListNode* head) {
	if(head == NULL || head->next == NULL)
		return 1;

	// get the middle node of the list
	ListNode *slow = head, *fast = head, *prev;
	while(fast != NULL && fast->next != NULL){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *first, *second;
	if(fast == NULL)
		second = slow;
	else if(fast->next == NULL)
		second = slow->next;
	prev->next = NULL;
	first = head;

	// reverse the second half of the list
	reverse(&second);

	// compare the first half to second half
	while(first != NULL && second != NULL){
		if(first->val != second->val)
			return 0;
		first = first->next;
		second = second->next;
	}
	return 1;
}