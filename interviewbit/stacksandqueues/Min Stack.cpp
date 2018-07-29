stack<int> main_stack, min_stack;
MinStack::MinStack() {
	
}

void MinStack::push(int x) {
	main_stack.push(x);
	if(min_stack.empty()){
		min_stack.push(x);
	}else{
		if(x <= min_stack.top()){
			min_stack.push(x);
		}else{
			min_stack.push(min_stack.top());
		}
	}
}

void MinStack::pop() {
	main_stack.pop();
	min_stack.pop();
}

int MinStack::top() {
	cout << main_stack.top();
	return main_stack.top();
}

int MinStack::getMin() {
	cout << min_stack.top();
	return min_stack.top();
}