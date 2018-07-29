/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *head, int K) {
	ListNode *prev = NULL, *curr = head, *next = NULL;
	int count = 0;
	while(curr != NULL && count < K){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if(next != NULL)
		head->next = reverse(next, K);
	return prev;
}

ListNode* Solution::reverseList(ListNode* head, int K) {
	if(head == NULL || head->next == NULL)
		return head;

	head = reverse(head, K);
	return head;
}