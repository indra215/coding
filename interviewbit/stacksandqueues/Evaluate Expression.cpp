bool isOperator(string s) {
	if(s == "+" || s == "-" || s == "*" || s == "/")
		return true;
	return false;
}

int Solution::evalRPN(vector<string> &expression) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(expression.empty())
		return 0;

	int len = expression.size(), i = 0;
	stack<int> values;

	while(i < len){
		if(!isOperator(expression[i])){
			values.push(stoi(expression[i]));
		}else{
			int n1 = values.top();
			values.pop();
			int n2 = values.top();
			values.pop();
			if(expression[i] == "+")
				values.push(n1+n2);
			else if(expression[i] == "-")
				values.push(n2-n1);
			else if(expression[i] == "*")
				values.push(n1*n2);
			else if(expression[i] == "/")
				values.push(n2/n1);
		}
		i++;
	}
	return values.top();
}