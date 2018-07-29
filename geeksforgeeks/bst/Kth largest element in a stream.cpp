#include <iostream>
#include <vector>

using namespace std;

class Minheap
{
private:
	vector<int> harr;
	int heap_size;
public:
	Minheap(vector<int>& arr, int size);
	void buildheap();
	int parent(int i);
	int left(int i);
	int right(int i);
	int getMin();
	void Minheapify(int i);
	void replaceMin(int i);
};

Minheap::Minheap(vector<int>& arr, int size)
{
	harr = arr;
	heap_size = size;
}

int Minheap::parent(int i)
{
	return (i-1)/2;
}

int Minheap::left(int i)
{
	return 2*i+1;
}

int Minheap::right(int i)
{
	return 2*i+2;
}

int Minheap::getMin()
{
	for(int i=0;i<harr.size();i++){
		cout << harr[i] << " ";
	}
	cout << "\n";
	return harr[0];
}

void Minheap::Minheapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heap_size && harr[l] < harr[i])
		smallest = l;
	if(r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	while(smallest != i){
		swap(harr[smallest], harr[i]);
		Minheapify(smallest);
	}
}

void Minheap::buildheap()
{
	int i = (heap_size - 1)/2;
	while(i >= 0){
		Minheapify(i);
		i--;
	}
}

void Minheap::replaceMin(int i)
{
	harr[0] = i;
	Minheapify(0);
}

void kthlargest(vector<int>& v, int N, int k)
{
	vector<int> arr(k);
	int count = 0, defaultv = -1;
	Minheap mh(arr, k);
	for(int i=0;i<N;i++){
		count++;
		if(count < k){
			cout << "Inside1\n";
			arr[count-1] = v[i];
			cout << defaultv << "\n";
		}else{
			cout << "Inside2\n";
			if(count == k){
				arr[count-1] = v[i];
				mh.buildheap();
			}else{
				if(v[i] > mh.getMin()){
					mh.replaceMin(v[i]);
				}
			}
			cout << mh.getMin() << "\n";
		}
	}
	cout << "\n";
}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int k, n;
		cin >> k >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		kthlargest(v, n, k);
	}
	return 0;
}