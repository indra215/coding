int Solution::strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(needle.empty())
		return -1;
	if(haystack.empty() && needle.empty())
		return -1;
	if(haystack.length() < needle.length())
		return -1;

	int i=0,hst,nst;
	while(i < haystack.length()){
		while(i < haystack.length() && haystack[i] != needle[0]){
			i++;
		}
		
		// if nothing matches
		if(i == haystack.length())
			return -1;

		hst = i;
		nst = 0;
		while(hst < haystack.length() && nst < needle.length()){
			if(haystack[hst] != needle[nst]){
				if(hst == haystack.length())
					return -1;
				else{
					break;
				}
			}
			hst++;
			nst++;
		}
		if(nst == needle.length())
			return i;
		i += 1;
	}
	return -1;
}