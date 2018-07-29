#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& v, int l, int mid, int h){
	if(l > h)
		return 0;
	int i = l, j = mid+1, inv_count = 0;
	vector<int> temp;
	while(i <= mid && j <= h){
		if(v[i] <= v[j]){
			temp.push_back(v[i]);
			i++;
		}else{
			temp.push_back(v[j]);
			// cout << mid-i << endl;
			inv_count += (mid-i+1);
			j++;
		}
	}
	while(i <= mid){
		temp.push_back(v[i]);
		i++;
	}
	while(j <= h){
		temp.push_back(v[j]);
		j++;
	}
	int k = 0;
	for(int i=l;i<=h;i++){
		v[i] = temp[k++];
	}
	return inv_count;
}

int mergerSort(vector<int>& v, int l, int h){
	if(l >= h)
		return 0;
	// cout << "MergeSort " << l << " " << h << "\n";
	int mid = l + (h-l)/2;
	// count inversions in left subarray
	int inv_count = 0;
	inv_count = mergerSort(v, l, mid);
	// count the inversions in right subarray
	inv_count += mergerSort(v, mid+1, h);
	// count the inversions in the merge process
	inv_count += merge(v, l, mid, h);

	return inv_count;
}

int countPairs(vector<int>& v, int N){
	// change the array by multiplying each element by its index
	for(int i=0;i<N;i++){
		v[i] *= i;
	}

	// now the problem is similar to counting inversions in array
	int inv_count = mergerSort(v, 0, N-1);
	return inv_count; 
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		int count_pairs = countPairs(v, N);
		cout << count_pairs << "\n";
	}

	return 0;
}