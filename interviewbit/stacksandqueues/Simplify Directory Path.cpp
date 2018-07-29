string Solution::simplifyPath(string directory) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(directory.empty())
		return string();

	stack<string> folders;
	string name;

	for(int i=0;i<directory.length();i++){
		if(directory[i] == '/'){
			if(!name.empty()){
				if(name == ".."){
					if(!folders.empty())
						folders.pop();
				}else if(name != "."){
					folders.push(name);
				}
				name.clear();
			}
		}else{
			name += directory[i];
		}
	}

	if(!name.empty()){
		if(name == ".."){
			if(!folders.empty())
				folders.pop();
		}else if(name != "."){
			folders.push(name);
		}
		name.clear();
	}

	if(folders.empty()){
		return "/";
	}

	string result;
	while(!folders.empty()){
		string s = folders.top();
		folders.pop();
		result = "/" + s + result;
	}

	return result;
}