#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
	int val, pos;
};

bool mycompare(Element a, Element b){
	return (a.val <= b.val);
}

int distance(vector<Element>& v, int N){
	if(N == 2){
		return abs(v[0].pos-v[1].pos);
	}
	sort(v.begin(), v.end(), mycompare);
	int ans = 0;
	for(int i=0;i<N-1;i++){
		ans += abs(v[i].pos - v[i+1].pos);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		vector<Element> v(N);
		for(int i=0;i<N;i++){
			int n;
			cin >> n;
			v[i].pos = i;
			v[i].val = n;
		}
		int ans = distance(v, N);
		cout << ans << "\n";
	}
	return 0;
}