/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* isCycle(ListNode *head){
	ListNode *slow = head, *fast = head;
	while(slow != NULL && fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return slow;	
	}
	if(fast == NULL || fast->next == NULL)
		return NULL;
}

ListNode* Solution::detectCycle(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(head->next == head)
		return head;

	ListNode *cycleNode = isCycle(head);
	if(cycleNode == NULL)
		return NULL;
	ListNode *curr = head;
	while(1){
		if(curr == cycleNode)
			break;
		cycleNode = cycleNode->next;
		curr = curr->next;
	}
	return cycleNode;
}