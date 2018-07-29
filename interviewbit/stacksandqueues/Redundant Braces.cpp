bool shouldPush(char ch) {
	if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	return false;
}

int Solution::braces(string expression) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(expression.empty())
		return 0;

	stack<char> operands;
	for(int i=0;i<expression.length();i++){
		if(shouldPush(expression[i])){
			operands.push(expression[i]);
		}else if(expression[i] == ')'){
			if(operands.top() == '(')
				return 1;
			while(1){
				char ch = operands.top();
				operands.pop();
				if(ch == '(')
					break;
			}
		}
	}

	return 0;
}