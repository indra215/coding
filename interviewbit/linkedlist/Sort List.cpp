/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void SplitList(ListNode *head, ListNode **first, ListNode **second){
	ListNode *slow = head, *fast = head, *prev = NULL;
	while(fast != NULL && fast->next != NULL){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast == NULL){
		prev->next = NULL;
		*second = slow;
	}else if(fast->next == NULL){
		*second = slow->next;
		slow->next = NULL;
	}
	*first = head;
}

ListNode *Merge(ListNode *first, ListNode *second){
	ListNode *result = NULL;
	if(first == NULL)
		return second;
	if(second == NULL)
		return first;
	if(first->val <= second->val){
		result = first;
		result->next = Merge(first->next, second);
	}else{
		result = second;
		result->next = Merge(first, second->next);
	}
	return result;
}

void MergeSort(ListNode **head){
	ListNode *curr = *head, *first, *second;
	if(curr == NULL || curr->next == NULL)
		return;
	SplitList(curr, &first, &second);
	MergeSort(&first);
	MergeSort(&second);
	*head = Merge(first, second);
}

ListNode* Solution::sortList(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(head == NULL || head->next == NULL)
		return head;

	MergeSort(&head);
	return head;
}