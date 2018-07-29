/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* SortedMerge(ListNode* headA, ListNode* headB){
	ListNode *result = NULL;
	if(headA == NULL)
		return headB;
	if(headB == NULL)
		return headA;
	if(headA->val <= headB->val){
		result = headA;
		result->next = SortedMerge(headA->next, headB);
	}else{
		result = headB;
		result->next = SortedMerge(headA, headB->next);
	}
	return result;
}

ListNode* Solution::mergeTwoLists(ListNode* headA, ListNode* headB) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	if(headA == NULL && headB == NULL)
		return NULL;
	if(headA == NULL)
		return headB;
	if(headB == NULL)
		return headA;

	ListNode *result;
	result = SortedMerge(headA, headB);
	return result;
}