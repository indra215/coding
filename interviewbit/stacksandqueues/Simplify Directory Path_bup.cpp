string Solution::simplifyPath(string directory) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(directory.empty())
		return string();

	size_t pos;
	stack<string> folders;
	while((pos = directory.find('/')) != string::npos){
		if(pos == 0){
			directory.erase(0, pos+1);
			continue;
		}
		
		string s = directory.substr(0, pos);
		
		if(s == ".."){
			if(!folders.empty()){
				folders.pop();
			}
		}else if(s != "."){
			folders.push(s);
		}
		directory.erase(0, pos+1);
	}

	if(!directory.empty()){
		if(directory == ".."){
			if(!folders.empty())
				folders.pop();
		}
		else if(directory != ".")
			folders.push(directory);
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