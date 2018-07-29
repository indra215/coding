/*
Sort elements by frequency
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ele{
	int index,count,val;
};

int comp_val(struct ele a, struct ele b){
	return a.val < b.val;
}

int comp_count_index(struct ele a, struct ele b){
	if(a.count != b.count)
		return a.count < b.count;
	else return a.index > b.index;
}

void sortByFreq(vector<int>& v){
	int n = v.size();

	vector<struct ele> element(n);
	for(int i=0;i<n;i++){
		element[i].index = i;
		element[i].count = 0;
		element[i].val = v[i];
	}

	// sort on the basis of value
	sort(element.begin(), element.end(), comp_val);

	// update the count entry
	element[0].count = 1;
	for(int i=1;i<n;i++){
		if(element[i].val == element[i-1].val){
			element[i].count += element[i-1].count + 1;
			element[i-1].count = -1;
			element[i].index = element[i-1].index;
		}else{
			element[i].count = 1;
		}
	}

	// sort the elements on the basis of count
	// if count is same sort on the basis of index (first come first one)
	sort(element.begin(), element.end(), comp_count_index);

	// arrange the elements in the array back
	int index = 0;
	for(int i=n-1;i>=0;i--){
		if(element[i].count != -1){
			for(int j=0;j<element[i].count;j++)
				v[index++] = element[i].val;
		}
	}

}

int main(){

	vector<int> v = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};

	cout << "Sorting\n";
	sortByFreq(v);

	cout << "After Sorting values are\n";
	for(int i=0;i<v.size();i++)
		cout << v[i] << " ";
	cout << "\n";

	return 0;
}