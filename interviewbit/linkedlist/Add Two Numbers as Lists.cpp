/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* headA, ListNode* headB) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(headA == NULL)
		return headB;
	if(headB == NULL)
		return headA;

	ListNode *result = NULL, *resultHead = NULL;
	int sum,carry = 0;
	while(headA != NULL && headB != NULL){
		sum = headA->val + headB->val + carry;
		carry = sum/10;
		sum = sum%10;
		ListNode *n = new ListNode(sum);
		if(result == NULL){
			result = n;
			resultHead = result;
		}else{
			result->next = n;
			result = result->next;
		}
		headA = headA->next;
		headB = headB->next;
	}
	while(headA != NULL){
		if(carry > 0){
			sum = headA->val + carry;
			carry = sum/10;
			sum = sum%10;
			ListNode *n = new ListNode(sum);
			result->next = n;
			result = result->next;
			headA = headA->next;
		}else{
			result->next = headA;
			break;
		}
	}
	while(headB != NULL){
		if(carry > 0){
			sum = headB->val + carry;
			carry = sum/10;
			sum = sum%10;
			ListNode *n = new ListNode(sum);
			result->next = n;
			result = result->next;
			headB = headB->next;
		}else{
			result->next = headB;
			break;
		}
		
	}
	if(carry > 0){
		ListNode *n = new ListNode(carry);
		result->next = n;
	}
	return resultHead;
}