/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void sortList(ListNode **sorted, ListNode *node){
	if(*sorted == NULL || (*sorted)->val >= node->val){
		node->next = *sorted;
		*sorted = node;
		return;
	}
	ListNode *curr = *sorted, *prev = NULL;
	while(curr != NULL){
		if(curr->val <= node->val){
			prev = curr;
			curr = curr->next;
		}else{
			prev->next = node;
			node->next = curr;
			break;
		}
	}
	if(curr == NULL){
		prev->next = node;
		node->next = curr;
	}
}

ListNode* Solution::insertionSortList(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(head == NULL || head->next == NULL)
		return head;
	ListNode *sorted = NULL, *curr = head, *next;
	while(curr != NULL){
		next = curr->next;
		sortList(&sorted, curr);
		curr = next;
	}
	return sorted;
}