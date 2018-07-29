#include <iostream>
#include <vector>

using namespace std;

int findSmaller(vector<int>& v, int N, int s, int e, int key){
	int mid;
	while(s < e){
		mid = s + (e - s)/2;
		// cout << s << " " << e << " " << mid << " " << v[mid] << "\n";
		if(v[mid] == key){
			while(v[mid+1] == key && mid+1 < N){
				mid++;
			}
			return mid+1;
		}
		else if(mid < N && (v[mid] < key && v[mid+1] > key)){
			return mid+1;
		}
		else if(mid > 0 && (v[mid-1] <= key && v[mid] > key)){
			return mid;
		}
		else if(v[mid] < key){
			s = mid+1;
		}else{
			e = mid-1;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N, key;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}
		cin >> key;
		int pos = findSmaller(v, N, 0, N-1, key);
		cout << pos << "\n";
	}	
	return 0;
}