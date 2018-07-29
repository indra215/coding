class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty())
        	return "";

        string name;
        stack<string> folders;
        for(int i=0;i<path.length();i++){
        	if(path[i] == '/'){
        		if(!name.empty()){
        			if(name == ".."){
        				if(!folders.empty())
	        				folders.pop();
        			}
        			else if(name != ".")
        				folders.push(name);
        			name.clear();
        		}
        	}else{
        		name += path[i];
        	}
        }

        if(!name.empty()){
			if(name == ".."){
				if(!folders.empty())
    				folders.pop();
			}
			else if(name != ".")
				folders.push(name);
			name.clear();
		}

        if(folders.empty())
        	return "/";

        string result;
        while(!folders.empty()){
        	result = "/" + folders.top() + result;
        	folders.pop();
        }

        return result;
    }
};