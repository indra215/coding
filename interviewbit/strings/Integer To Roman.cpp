string Solution::intToRoman(int num) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<string> romans = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	vector<int> integers = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	string roman;

	for(int i=0;i<integers.size();i++){
		while(integers[i] <= num){
			num -= integers[i];
			roman.append(romans[i]);
		}
	}
	return roman;
}